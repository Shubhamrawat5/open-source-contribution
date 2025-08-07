/**
 * 🧠 Mind-Blowing TypeScript Utility: Advanced Type-Safe Query Builder
 *
 * A zero-dependency, type-safe query builder that uses advanced TypeScript
 * features to provide compile-time safety and runtime efficiency.
 *
 * Features:
 * - 100% Type Safe with IntelliSense support
 * - Zero runtime overhead for type checking
 * - Fluent API with method chaining
 * - Advanced conditional types and template literals
 * - Recursive type inference
 *
 * @author Your Name
 * @version 1.0.0
 */

// 🔥 Advanced Type Utilities
type DeepReadonly<T> = {
    readonly [P in keyof T]: T[P] extends object ? DeepReadonly<T[P]> : T[P];
  };
  
  type KeysOfType<T, U> = {
    [K in keyof T]: T[K] extends U ? K : never;
  }[keyof T];
  
  type StringKeys<T> = KeysOfType<T, string>;
  type NumberKeys<T> = KeysOfType<T, number>;
  type BooleanKeys<T> = KeysOfType<T, boolean>;
  
  // 🎯 SQL-like operators with type safety
  type ComparisonOperator =
    | "eq"
    | "ne"
    | "gt"
    | "gte"
    | "lt"
    | "lte"
    | "in"
    | "like";
  type LogicalOperator = "and" | "or";
  
  // 🚀 Advanced conditional types for operator validation
  type ValidOperatorForType<T> = T extends string
    ? ComparisonOperator
    : T extends number
    ? Exclude<ComparisonOperator, "like">
    : T extends boolean
    ? "eq" | "ne"
    : never;
  
  // 🧩 Template literal types for dynamic method generation
  type WhereMethod<T, K extends keyof T> = `where${Capitalize<string & K>}`;
  type OrderMethod<T, K extends keyof T> = `orderBy${Capitalize<string & K>}`;
  
  // 🎨 Query condition interface
  interface QueryCondition<T, K extends keyof T> {
    field: K;
    operator: ValidOperatorForType<T[K]>;
    value: T[K] | T[K][];
    logical?: LogicalOperator;
  }
  
  // 🌟 Main Query Builder Class
  class TypeSafeQueryBuilder<T extends Record<string, any>> {
    private conditions: QueryCondition<T, keyof T>[] = [];
    private orderField?: keyof T;
    private orderDirection: "asc" | "desc" = "asc";
    private limitValue?: number;
    private offsetValue?: number;
  
    constructor(private schema: T) {}
  
    // 🔗 Fluent where clause with type safety
    where<K extends keyof T>(
      field: K,
      operator: ValidOperatorForType<T[K]>,
      value: T[K] | T[K][]
    ): this {
      this.conditions.push({ field, operator, value });
      return this;
    }
  
    // 🔗 Logical operators
    and<K extends keyof T>(
      field: K,
      operator: ValidOperatorForType<T[K]>,
      value: T[K] | T[K][]
    ): this {
      this.conditions.push({ field, operator, value, logical: "and" });
      return this;
    }
  
    or<K extends keyof T>(
      field: K,
      operator: ValidOperatorForType<T[K]>,
      value: T[K] | T[K][]
    ): this {
      this.conditions.push({ field, operator, value, logical: "or" });
      return this;
    }
  
    // 🎯 Type-safe ordering
    orderBy<K extends keyof T>(
      field: K,
      direction: "asc" | "desc" = "asc"
    ): this {
      this.orderField = field;
      this.orderDirection = direction;
      return this;
    }
  
    // 📊 Pagination
    limit(count: number): this {
      this.limitValue = count;
      return this;
    }
  
    offset(count: number): this {
      this.offsetValue = count;
      return this;
    }
  
    // 🏗️ Build final query object
    build(): DeepReadonly<{
      conditions: QueryCondition<T, keyof T>[];
      order?: { field: keyof T; direction: "asc" | "desc" };
      pagination?: { limit?: number; offset?: number };
    }> {
      const query: any = { conditions: [...this.conditions] };
  
      if (this.orderField) {
        query.order = { field: this.orderField, direction: this.orderDirection };
      }
  
      if (this.limitValue !== undefined || this.offsetValue !== undefined) {
        query.pagination = {};
        if (this.limitValue !== undefined)
          query.pagination.limit = this.limitValue;
        if (this.offsetValue !== undefined)
          query.pagination.offset = this.offsetValue;
      }
  
      return query as DeepReadonly<typeof query>;
    }
  
    // 🎭 Convert to SQL-like string (for demonstration)
    toSQL(): string {
      let sql = "SELECT * FROM table";
  
      if (this.conditions.length > 0) {
        sql += " WHERE ";
        sql += this.conditions
          .map((condition, index) => {
            const prefix =
              index > 0 && condition.logical
                ? ` ${condition.logical.toUpperCase()} `
                : "";
            const operator = this.getSQLOperator(condition.operator);
            const value = Array.isArray(condition.value)
              ? `(${condition.value
                  .map((v) => (typeof v === "string" ? `'${v}'` : v))
                  .join(", ")})`
              : typeof condition.value === "string"
              ? `'${condition.value}'`
              : condition.value;
  
            return `${prefix}${String(condition.field)} ${operator} ${value}`;
          })
          .join("");
      }
  
      if (this.orderField) {
        sql += ` ORDER BY ${String(
          this.orderField
        )} ${this.orderDirection.toUpperCase()}`;
      }
  
      if (this.limitValue) {
        sql += ` LIMIT ${this.limitValue}`;
      }
  
      if (this.offsetValue) {
        sql += ` OFFSET ${this.offsetValue}`;
      }
  
      return sql;
    }
  
    private getSQLOperator(op: ComparisonOperator): string {
      const mapping: Record<ComparisonOperator, string> = {
        eq: "=",
        ne: "!=",
        gt: ">",
        gte: ">=",
        lt: "<",
        lte: "<=",
        in: "IN",
        like: "LIKE",
      };
      return mapping[op];
    }
  }
  
  // 🏭 Factory function with advanced type inference
  function createQueryBuilder<T extends Record<string, any>>(schema: T) {
    return new TypeSafeQueryBuilder(schema);
  }
  
  // 🎪 Advanced decorator for method timing (decorator factory)
  function measureTime(): MethodDecorator {
    return function (
      target: Object,
      propertyKey: string | symbol,
      descriptor: PropertyDescriptor
    ) {
      const originalMethod = descriptor.value;
      descriptor.value = function (this: any, ...args: any[]) {
        const start = performance.now();
        const result = originalMethod.apply(this, args);
        const end = performance.now();
        console.log(
          `⚡ ${String(propertyKey)} executed in ${(end - start).toFixed(2)}ms`
        );
        return result;
      };
      return descriptor;
    };
  }
  
  // 🎨 Example usage with type safety
  interface User {
    id: number;
    name: string;
    email: string;
    age: number;
    isActive: boolean;
    createdAt: Date;
  }
  
  // 🧪 Example implementation
  class UserService {
    private queryBuilder = createQueryBuilder<User>({} as User);
  
    @measureTime()
    findActiveUsers(minAge: number = 18): string {
      return this.queryBuilder
        .where("isActive", "eq", true)
        .and("age", "gte", minAge)
        .orderBy("createdAt", "desc")
        .limit(10)
        .toSQL();
    }
  
    @measureTime()
    searchUsers(searchTerm: string): string {
      return this.queryBuilder
        .where("name", "like", `%${searchTerm}%`)
        .or("email", "like", `%${searchTerm}%`)
        .orderBy("name", "asc")
        .build() as any; // Would return the actual query object
    }
  }
  
  // 🎯 Advanced utility types for API responses
  type ApiResponse<T> = {
    data: T;
    meta: {
      total: number;
      page: number;
      hasNext: boolean;
    };
    timestamp: number;
  };
  
  // 🚀 Generic HTTP client with type safety
  class TypeSafeHttpClient {
    async get<T>(url: string): Promise<ApiResponse<T>> {
      // Simulate API call
      return new Promise<ApiResponse<T>>((resolve) => {
        setTimeout(() => {
          resolve({
            data: {} as T,
            meta: { total: 0, page: 1, hasNext: false },
            timestamp: Date.now(),
          });
        }, 100);
      });
    }
  }
  
  // 🎉 Export everything for use
  export {
    TypeSafeQueryBuilder,
    createQueryBuilder,
    measureTime,
    UserService,
    TypeSafeHttpClient,
  };
  
  export type {
    DeepReadonly,
    KeysOfType,
    ComparisonOperator,
    LogicalOperator,
    QueryCondition,
    ApiResponse,
    User,
  };
  
  // 🌟 Usage examples in comments:
  /*
    const userQuery = createQueryBuilder<User>({} as User);
    
    // ✅ Type-safe - this works
    const query1 = userQuery
      .where('age', 'gte', 25)          // ✅ number field with valid operator
      .and('name', 'like', 'John%')     // ✅ string field with valid operator
      .or('isActive', 'eq', true)       // ✅ boolean field with valid operator
      .orderBy('createdAt', 'desc')     // ✅ valid field for ordering
      .limit(10)
      .toSQL();
    
    // ❌ Type errors - these won't compile:
    // userQuery.where('age', 'like', 25)        // ❌ 'like' not valid for number
    // userQuery.where('isActive', 'gt', true)   // ❌ 'gt' not valid for boolean
    // userQuery.where('invalidField', 'eq', 1)  // ❌ field doesn't exist
    */
  