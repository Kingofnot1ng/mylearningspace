/*
react-native-modal-dropdown demo
Dependencies: yarn add react-native-modal-dropdown
————————————————
版权声明：本文为CSDN博主「marsur」的原创文章，遵循CC 4.0 BY-SA版权协议，转载请附上原文出处链接及本声明。
原文链接：https://blog.csdn.net/marsur/article/details/103556733
 */

import React from 'react';
import { Component } from 'react';
import {
  Text,
  View,
} from 'react-native';
import ModalDropdown from 'react-native-modal-dropdown';

const type=['国内','国外'];

class Index extends Component{
  constructor(props){
    super(props);
    this.state={
      areaIndex: '0',
      typeShow: false
    }
  }
  // 分类选择
  _selectType = (index,value) => {
    console.log(index + '--' + value)
    this.setState({
        areaIndex: index
    })
  }
// 下拉列表分隔符
  _separator = () => {
    return(
        <Text style={{height:0}}></Text>
    )
  }
// 分类选择下拉框位置
  _adjustType = () => {
    return({
        top: 40,
        left: 10
    })
  }
  render(){
    return(
      <View>
        <Text>这是一个下拉列表demo</Text>
        <ModalDropdown
		      options={type}    //下拉内容数组
		      // style={styles.dropdown}    //按钮样式
		       dropdownStyle={{height:36*type.length,width:40}}    //下拉框样式
		      // dropdownTextStyle={styles.dropdownText}    //下拉框文本样式
		      renderSeparator={this._separator}    //下拉框文本分隔样式
		      adjustFrame={this._adjustType}    //下拉框位置
		      dropdownTextHighlightStyle={{color:'rgba(42, 130, 228, 1)'}}    //下拉框选中颜色
		      onDropdownWillShow={() => {this.setState({typeShow:true})}}      //按下按钮显示按钮时触发
		      onDropdownWillHide={() => this.setState({typeShow:false})}    //当下拉按钮通过触摸按钮隐藏时触发
		      onSelect={this._selectType}    //当选项行与选定的index 和 value 接触时触发
		      defaultValue={'国内'}>
		      <Text style={{color: '#444'}}>{this.state.areaIndex === '0'?'国内':'国外'}</Text>
        </ModalDropdown>
      </View>
    )
  }
}

export default Index
