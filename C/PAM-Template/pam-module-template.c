/*
This c file provides a template to write your own Pluggable Authentication Module (PAM)
that can be injected into your linux machine enabled with PAM.
*/
#define PAM_SM_AUTH
#include <security/pam_modules.h>
#include <security/pam_ext.h>
#include <stdio.h>
#include <string.h>
#include <syslog.h>

// Authentication function (auth phase)
PAM_EXTERN int pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    const char *username = NULL;
    const char *password = NULL;
    int retval;

    // Get the username from PAM environment
    retval = pam_get_user(pamh, &username, NULL);
    if (retval != PAM_SUCCESS) {
        return retval;
    }

    // Get the password entered by the user
    retval = pam_get_authtok(pamh, PAM_AUTHTOK, &password, NULL);
    if (retval != PAM_SUCCESS) {
        return retval;
    }

    // Check the password (this is just a dummy check, replace with actual logic)
    if (strcmp(password, "Abcd$1234") != 0) {
        pam_syslog(pamh, LOG_ERR, "Authentication failed for user %s", username);
        return PAM_AUTH_ERR;  // Return authentication failure
    }

    // Authentication is success at this state. You can find the below log in /var/log/auth.log file
    pam_syslog(pamh, LOG_INFO, "Authentication succeeded for user %s", username);
    return PAM_SUCCESS;  // Return authentication success
}

/*
  Above pam_sm_authenticate function provides a overall idea on how to write a phase.
*/

PAM_EXTERN int pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    return PAM_SUCCESS;
}

// Account management function (account phase)
PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    printf("Account management");
    return PAM_SUCCESS;
}

// Password management function (password phase)
PAM_EXTERN int pam_sm_chauthtok(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    printf("Changing authentication token");
    return PAM_SUCCESS;
}

/* Session management functions (session phase) */
PAM_EXTERN int pam_sm_open_session(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    printf("Opening session");
    return PAM_SUCCESS;
}

PAM_EXTERN int pam_sm_close_session(pam_handle_t *pamh, int flags, int argc, const char **argv) {
    printf("Closing session");
    return PAM_SUCCESS;
}
