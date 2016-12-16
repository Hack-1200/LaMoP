require 'test_helper'

class TabinfsControllerTest < ActionDispatch::IntegrationTest
  setup do
    @tabinf = tabinfs(:one)
  end

  test "should get index" do
    get tabinfs_url
    assert_response :success
  end

  test "should get new" do
    get new_tabinf_url
    assert_response :success
  end

  test "should create tabinf" do
    assert_difference('Tabinf.count') do
      post tabinfs_url, params: { tabinf: { address: @tabinf.address, datro: @tabinf.datro, fio: @tabinf.fio, mestoro: @tabinf.mestoro, ntel: @tabinf.ntel, sex: @tabinf.sex } }
    end

    assert_redirected_to tabinf_url(Tabinf.last)
  end

  test "should show tabinf" do
    get tabinf_url(@tabinf)
    assert_response :success
  end

  test "should get edit" do
    get edit_tabinf_url(@tabinf)
    assert_response :success
  end

  test "should update tabinf" do
    patch tabinf_url(@tabinf), params: { tabinf: { address: @tabinf.address, datro: @tabinf.datro, fio: @tabinf.fio, mestoro: @tabinf.mestoro, ntel: @tabinf.ntel, sex: @tabinf.sex } }
    assert_redirected_to tabinf_url(@tabinf)
  end

  test "should destroy tabinf" do
    assert_difference('Tabinf.count', -1) do
      delete tabinf_url(@tabinf)
    end

    assert_redirected_to tabinfs_url
  end
end
