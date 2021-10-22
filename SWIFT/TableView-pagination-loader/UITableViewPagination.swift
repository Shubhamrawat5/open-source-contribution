import Foundation
import UIKit

private var loadingView: UIView!
private var indicator: UIActivityIndicatorView!

extension UITableView{
    
    private func createLoadingView() {
        loadingView = UIView(frame: CGRect(x: 0, y: 0, width: frame.width, height: 50))
        indicator = UIActivityIndicatorView()
        indicator.color = #colorLiteral(red: 0.4941176471, green: 0.3411764706, blue: 0.7607843137, alpha: 1)
        indicator.translatesAutoresizingMaskIntoConstraints = false
        indicator.startAnimating()
        loadingView.addSubview(indicator)
        centerIndicator()
        self.tableFooterView = loadingView
    }
    
    private func centerIndicator() {
        let xCenterConstraint = NSLayoutConstraint(
            item: loadingView!, attribute: .centerX, relatedBy: .equal,
            toItem: indicator, attribute: .centerX, multiplier: 1, constant: 0
        )
        loadingView.addConstraint(xCenterConstraint)
        
        let yCenterConstraint = NSLayoutConstraint(
            item: loadingView!, attribute: .centerY, relatedBy: .equal,
            toItem: indicator, attribute: .centerY, multiplier: 1, constant: 0
        )
        loadingView.addConstraint(yCenterConstraint)
    }
    
    
    func showLoading() {
        if loadingView == nil {
            createLoadingView()
        }
        self.tableFooterView = loadingView
    }
    
    func hideLoading() {
        self.tableFooterView = nil
    }
    }
