	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_0809f64c
FUN_0809f64c: @ 0x0809F64C
	ldr r1, _0809F654 @ =0x03000144
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_0809F654: .4byte 0x03000144

	thumb_func_start FUN_0809f658
FUN_0809f658: @ 0x0809F658
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	ldr r0, _0809F668 @ =0x03000144
	ldr r0, [r0]
	cmp r0, #0
	bne _0809F676
	b _0809F6E4
	.align 2, 0
_0809F668: .4byte 0x03000144
_0809F66C:
	adds r1, r3, #0
	adds r1, #0xdf
	movs r0, #1
	strb r0, [r1]
	b _0809F6E6
_0809F676:
	movs r4, #0
	ldrh r1, [r0, #0x18]
	cmp r4, r1
	bge _0809F6E4
	mov ip, r0
	adds r6, r1, #0
_0809F682:
	movs r0, #0xf4
	muls r0, r4, r0
	adds r0, #0x1c
	mov r1, ip
	adds r3, r1, r0
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F6DE
	movs r2, #0x1e
	ldrsh r1, [r3, r2]
	movs r7, #2
	ldrsh r0, [r5, r7]
	cmp r1, r0
	blt _0809F6DE
	movs r0, #0
	ldrsh r1, [r5, r0]
	movs r2, #0x1c
	ldrsh r0, [r3, r2]
	subs r2, r1, r0
	cmp r2, #0
	bge _0809F6B2
	rsbs r2, r2, #0
_0809F6B2:
	cmp r2, #0x80
	bgt _0809F6DE
	movs r7, #4
	ldrsh r1, [r5, r7]
	movs r7, #0x20
	ldrsh r0, [r3, r7]
	subs r1, r1, r0
	cmp r1, #0
	bge _0809F6C6
	rsbs r1, r1, #0
_0809F6C6:
	cmp r1, #0x80
	bgt _0809F6DE
	adds r0, r2, #0
	muls r0, r2, r0
	adds r2, r1, #0
	muls r2, r1, r2
	adds r1, r2, #0
	adds r0, r0, r1
	movs r1, #0x80
	lsls r1, r1, #7
	cmp r0, r1
	ble _0809F66C
_0809F6DE:
	adds r4, #1
	cmp r4, r6
	blt _0809F682
_0809F6E4:
	movs r0, #0
_0809F6E6:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809f6ec
FUN_0809f6ec: @ 0x0809F6EC
	push {r4, r5, lr}
	ldr r4, _0809F704 @ =0x03000144
	ldr r0, [r4]
	cmp r0, #0
	beq _0809F738
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	bne _0809F710
	b _0809F738
	.align 2, 0
_0809F704: .4byte 0x03000144
_0809F708:
	adds r0, r2, #0
	adds r0, #0xf8
	ldrb r0, [r0]
	b _0809F73C
_0809F710:
	bl VM_GetValue
	adds r5, r0, #0
	movs r3, #0
	ldr r0, [r4]
	ldrh r1, [r0, #0x18]
	cmp r3, r1
	bge _0809F738
	adds r4, r1, #0
	adds r1, r0, #0
	adds r1, #0xfc
	adds r2, r0, #0
_0809F728:
	ldrh r0, [r1]
	cmp r0, r5
	beq _0809F708
	adds r1, #0xf4
	adds r2, #0xf4
	adds r3, #1
	cmp r3, r4
	blt _0809F728
_0809F738:
	movs r0, #1
	rsbs r0, r0, #0
_0809F73C:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_0809f744
FUN_0809f744: @ 0x0809F744
	mov ip, r0
	adds r0, #0xdc
	movs r3, #0
	strb r1, [r0]
	adds r0, #0x14
	str r2, [r0]
	subs r0, #4
	strh r3, [r0]
	adds r0, #2
	strh r3, [r0]
	bx lr
	.align 2, 0

	thumb_func_start FUN_0809f75c
FUN_0809f75c: @ 0x0809F75C
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	adds r7, r1, #0
	adds r3, r2, #0
	adds r5, r3, #0
	adds r6, r7, #0
	adds r6, #0x44
	ldrh r0, [r6]
	cmp r0, #0
	bne _0809F7F6
	movs r1, #4
	ldr r0, [r4, #0x34]
	ands r0, r1
	cmp r0, #0
	beq _0809F7F6
	ldr r2, [r4, #0x38]
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _0809F7BC
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7A0
	ldr r2, _0809F79C @ =FUN_0809f938
	adds r0, r3, #0
	movs r1, #2
	bl FUN_0809f744
	b _0809F7AE
	.align 2, 0
_0809F79C: .4byte FUN_0809f938
_0809F7A0:
	cmp r0, #1
	bne _0809F7AE
	ldr r2, _0809F7B8 @ =FUN_0809f890
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809F7AE:
	adds r1, r7, #0
	adds r1, #0x44
	movs r0, #0x1e
	strh r0, [r1]
	b _0809F7F6
	.align 2, 0
_0809F7B8: .4byte FUN_0809f890
_0809F7BC:
	movs r0, #8
	ands r2, r0
	cmp r2, #0
	beq _0809F7E4
	adds r0, r3, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7D8
	ldr r2, _0809F7E0 @ =FUN_0809f840
	adds r0, r3, #0
	movs r1, #1
	bl FUN_0809f744
_0809F7D8:
	movs r0, #0x1e
	strh r0, [r6]
	b _0809F7F6
	.align 2, 0
_0809F7E0: .4byte FUN_0809f840
_0809F7E4:
	adds r0, r5, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809F7F6
	adds r1, r5, #0
	adds r1, #0xdf
	movs r0, #1
	strb r0, [r1]
_0809F7F6:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809f7fc
FUN_0809f7fc: @ 0x0809F7FC
	push {lr}
	adds r3, r0, #0
	ldr r0, _0809F830 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809F834 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0809F82C
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _0809F838 @ =0x012B0000
	cmp r1, r0
	ble _0809F82C
	ldr r2, _0809F83C @ =FUN_0809f890
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809F82C:
	pop {r0}
	bx r0
	.align 2, 0
_0809F830: .4byte 0x030046A0
_0809F834: .4byte 0x00000942
_0809F838: .4byte 0x012B0000
_0809F83C: .4byte FUN_0809f890

	thumb_func_start FUN_0809f840
FUN_0809f840: @ 0x0809F840
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xee
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809F854
	ldr r0, _0809F868 @ =0x0000019F
	bl PlaySound_082406e0
_0809F854:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F86C
	movs r0, #3
	strh r0, [r5, #0x10]
	b _0809F884
	.align 2, 0
_0809F868: .4byte 0x0000019F
_0809F86C:
	cmp r0, #0xf
	bhi _0809F876
	movs r0, #4
	strh r0, [r5, #0x10]
	b _0809F884
_0809F876:
	movs r0, #5
	strh r0, [r5, #0x10]
	ldr r2, _0809F88C @ =FUN_0809f7fc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0809f744
_0809F884:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F88C: .4byte FUN_0809f7fc

	thumb_func_start FUN_0809f890
FUN_0809f890: @ 0x0809F890
	push {r4, r5, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0xee
	ldrh r0, [r4]
	cmp r0, #0
	bne _0809F8A6
	movs r0, #0xd0
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809F8A6:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F8BA
	movs r0, #4
	strh r0, [r5, #0x10]
	b _0809F8DA
_0809F8BA:
	cmp r0, #0xf
	bhi _0809F8C4
	movs r0, #3
	strh r0, [r5, #0x10]
	b _0809F8DA
_0809F8C4:
	movs r0, #2
	strh r0, [r5, #0x10]
	movs r0, #0xd0
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r2, _0809F8E0 @ =FUN_0809fabc
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0809f744
_0809F8DA:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809F8E0: .4byte FUN_0809fabc

	thumb_func_start FUN_0809f8e4
FUN_0809f8e4: @ 0x0809F8E4
	push {lr}
	adds r3, r0, #0
	movs r1, #0x80
	lsls r1, r1, #4
	ldr r0, _0809F900 @ =0x030046A0
	ldr r0, [r0]
	ldr r2, _0809F904 @ =0x00000934
	adds r0, r0, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _0809F908
	movs r0, #1
	b _0809F90A
	.align 2, 0
_0809F900: .4byte 0x030046A0
_0809F904: .4byte 0x00000934
_0809F908:
	movs r0, #0
_0809F90A:
	cmp r0, #0
	beq _0809F92A
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _0809F930 @ =0x012B0000
	cmp r1, r0
	ble _0809F92A
	ldr r2, _0809F934 @ =FUN_0809fa80
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809F92A:
	pop {r0}
	bx r0
	.align 2, 0
_0809F930: .4byte 0x012B0000
_0809F934: .4byte FUN_0809fa80

	thumb_func_start FUN_0809f938
FUN_0809f938: @ 0x0809F938
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x14
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xee
	ldrh r0, [r5]
	cmp r0, #0
	bne _0809F954
	movs r0, #0xae
	lsls r0, r0, #1
	bl PlaySound_082406e0
_0809F954:
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809F9D8
	movs r0, #6
	strh r0, [r4, #0x10]
	ldrh r1, [r5]
	movs r0, #3
	ands r0, r1
	cmp r0, #0
	beq _0809F972
	b _0809FA6E
_0809F972:
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #4]
	str r1, [sp, #8]
	ldr r6, _0809F9C8 @ =0x0203B400
	ldr r5, _0809F9CC @ =0x030046B8
	ldr r2, [r5]
	adds r2, #1
	ldr r4, _0809F9D0 @ =0x000003FF
	ands r2, r4
	lsls r3, r2, #1
	adds r3, r3, r6
	add r0, sp, #4
	ldrh r1, [r0]
	subs r1, #0x7f
	ldrb r3, [r3]
	adds r1, r1, r3
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r3, _0809F9D4 @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r2, r2, #1
	adds r2, r2, r6
	add r0, sp, #4
	ldrh r0, [r0, #4]
	subs r0, #0x7f
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #8]
	ands r1, r3
	orrs r1, r0
	str r1, [sp, #8]
	add r0, sp, #4
	str r0, [sp]
	b _0809FA40
	.align 2, 0
_0809F9C8: .4byte 0x0203B400
_0809F9CC: .4byte 0x030046B8
_0809F9D0: .4byte 0x000003FF
_0809F9D4: .4byte 0xFFFF0000
_0809F9D8:
	cmp r0, #0xf
	bhi _0809FA60
	movs r0, #7
	strh r0, [r4, #0x10]
	ldrh r0, [r5]
	adds r0, #1
	strh r0, [r5]
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _0809FA6E
	ldr r0, [r4, #0x1c]
	ldr r1, [r4, #0x20]
	str r0, [sp, #0xc]
	str r1, [sp, #0x10]
	ldr r0, _0809FA50 @ =0x0203B400
	mov r8, r0
	ldr r6, _0809FA54 @ =0x030046B8
	ldr r2, [r6]
	adds r2, #1
	ldr r4, _0809FA58 @ =0x000003FF
	ands r2, r4
	lsls r0, r2, #1
	add r0, r8
	add r3, sp, #0xc
	ldrh r1, [r3]
	subs r1, #0x7f
	ldrb r0, [r0]
	adds r1, r1, r0
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r5, _0809FA5C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r5
	orrs r0, r1
	str r0, [sp, #0xc]
	adds r2, #1
	ands r2, r4
	str r2, [r6]
	lsls r2, r2, #1
	add r2, r8
	ldrh r0, [r3, #4]
	subs r0, #0x7f
	ldrb r2, [r2]
	adds r0, r0, r2
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [r3, #4]
	ands r1, r5
	orrs r1, r0
	str r1, [r3, #4]
	str r3, [sp]
_0809FA40:
	movs r0, #1
	movs r1, #0
	movs r2, #1
	movs r3, #0x40
	bl FUN_08015c90
	b _0809FA6E
	.align 2, 0
_0809FA50: .4byte 0x0203B400
_0809FA54: .4byte 0x030046B8
_0809FA58: .4byte 0x000003FF
_0809FA5C: .4byte 0xFFFF0000
_0809FA60:
	movs r0, #8
	strh r0, [r4, #0x10]
	ldr r2, _0809FA7C @ =FUN_0809f8e4
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0809f744
_0809FA6E:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0809FA7C: .4byte FUN_0809f8e4

	thumb_func_start FUN_0809fa80
FUN_0809fa80: @ 0x0809FA80
	push {lr}
	adds r3, r0, #0
	adds r1, r3, #0
	adds r1, #0xee
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _0809FA9C
	movs r0, #7
	strh r0, [r3, #0x10]
	b _0809FAB4
_0809FA9C:
	cmp r0, #0xf
	bhi _0809FAA6
	movs r0, #6
	strh r0, [r3, #0x10]
	b _0809FAB4
_0809FAA6:
	movs r0, #2
	strh r0, [r3, #0x10]
	ldr r2, _0809FAB8 @ =FUN_0809fabc
	adds r0, r3, #0
	movs r1, #0
	bl FUN_0809f744
_0809FAB4:
	pop {r0}
	bx r0
	.align 2, 0
_0809FAB8: .4byte FUN_0809fabc

	thumb_func_start FUN_0809fabc
FUN_0809fabc: @ 0x0809FABC
	push {lr}
	adds r3, r0, #0
	movs r0, #0xdf
	adds r0, r0, r3
	mov ip, r0
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FAF4
	adds r2, r3, #0
	adds r2, #0xe5
	movs r1, #0
	movs r0, #1
	strb r0, [r2]
	mov r0, ip
	strb r1, [r0]
	adds r2, #9
	ldrh r1, [r2]
	cmp r1, #0x3f
	bls _0809FAEE
	ldrh r0, [r2]
	subs r0, #0x40
	movs r1, #0x1f
	ands r0, r1
	asrs r0, r0, #1
	b _0809FAF2
_0809FAEE:
	movs r0, #0xf
	ands r0, r1
_0809FAF2:
	strh r0, [r2]
_0809FAF4:
	movs r1, #0xe5
	adds r1, r1, r3
	mov ip, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809FB46
	adds r2, r3, #0
	adds r2, #0xee
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x5f
	bls _0809FB22
	movs r0, #2
	strh r0, [r3, #0x10]
	movs r0, #0
	mov r1, ip
	strb r0, [r1]
	movs r0, #0
	strh r0, [r2]
	b _0809FB46
_0809FB22:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3f
	bhi _0809FB36
	movs r0, #0xf
	ands r1, r0
	cmp r1, #7
	bhi _0809FB42
	movs r0, #1
	b _0809FB44
_0809FB36:
	movs r0, #0x1f
	ands r1, r0
	cmp r1, #0xf
	bhi _0809FB42
	movs r0, #1
	b _0809FB44
_0809FB42:
	movs r0, #2
_0809FB44:
	strh r0, [r3, #0x10]
_0809FB46:
	ldr r0, _0809FB78 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809FB7C @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r2, [r0, r1]
	cmp r2, #0
	bne _0809FBA8
	adds r0, r3, #0
	adds r0, #0xdd
	ldrb r1, [r0]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809FB80
	adds r1, r3, #0
	adds r1, #0xec
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bge _0809FBEE
	strh r2, [r1]
	b _0809FBEE
	.align 2, 0
_0809FB78: .4byte 0x030046A0
_0809FB7C: .4byte 0x00000942
_0809FB80:
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	subs r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x10
	ldr r0, _0809FBA0 @ =0xFFFFFED4
	cmp r1, r0
	bge _0809FBEE
	ldr r2, _0809FBA4 @ =FUN_0809f840
	adds r0, r3, #0
	movs r1, #1
	bl FUN_0809f744
	b _0809FBEE
	.align 2, 0
_0809FBA0: .4byte 0xFFFFFED4
_0809FBA4: .4byte FUN_0809f840
_0809FBA8:
	cmp r2, #7
	ble _0809FBEE
	adds r0, r3, #0
	adds r0, #0xdd
	ldrb r1, [r0]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0809FBD0
	adds r1, r3, #0
	adds r1, #0xec
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	ble _0809FBEE
	movs r0, #0
	strh r0, [r1]
	b _0809FBEE
_0809FBD0:
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	movs r0, #0x96
	lsls r0, r0, #0x11
	cmp r1, r0
	ble _0809FBEE
	ldr r2, _0809FBF4 @ =FUN_0809f938
	adds r0, r3, #0
	movs r1, #2
	bl FUN_0809f744
_0809FBEE:
	pop {r0}
	bx r0
	.align 2, 0
_0809FBF4: .4byte FUN_0809f938

	thumb_func_start FUN_0809fbf8
FUN_0809fbf8: @ 0x0809FBF8
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r0, #0xe6
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FCC4
	adds r0, r4, #0
	adds r0, #0xe8
	ldrh r1, [r0]
	ldr r0, _0809FC40 @ =0x030046A0
	ldr r0, [r0]
	movs r2, #0x92
	lsls r2, r2, #2
	adds r0, r0, r2
	ldr r0, [r0]
	cmp r1, r0
	bne _0809FC48
	adds r0, r4, #0
	adds r0, #0xe7
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809FC30
	adds r2, r4, #0
	adds r2, #0x92
	ldrh r1, [r2]
	ldr r0, _0809FC44 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
_0809FC30:
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	b _0809FCD0
	.align 2, 0
_0809FC40: .4byte 0x030046A0
_0809FC44: .4byte 0x0000FFFB
_0809FC48:
	adds r0, r4, #0
	adds r0, #0xe7
	ldrb r1, [r0]
	adds r6, r0, #0
	cmp r1, #0
	beq _0809FCD0
	subs r0, #0xb
	ldrb r5, [r0]
	cmp r5, #0
	bne _0809FC7C
	ldr r2, _0809FC78 @ =FUN_0809fabc
	adds r0, r4, #0
	movs r1, #0
	bl FUN_0809f744
	movs r0, #0
	strh r5, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0xe5
	strb r0, [r1]
	subs r1, #6
	strb r0, [r1]
	b _0809FCAE
	.align 2, 0
_0809FC78: .4byte FUN_0809fabc
_0809FC7C:
	cmp r5, #2
	bne _0809FC94
	ldr r2, _0809FC90 @ =FUN_0809f8e4
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0809f744
	movs r0, #8
	b _0809FCA4
	.align 2, 0
_0809FC90: .4byte FUN_0809f8e4
_0809FC94:
	cmp r5, #1
	bne _0809FCAE
	ldr r2, _0809FCC0 @ =FUN_0809f7fc
	adds r0, r4, #0
	movs r1, #2
	bl FUN_0809f744
	movs r0, #5
_0809FCA4:
	strh r0, [r4, #0x10]
	adds r1, r4, #0
	adds r1, #0xe2
	movs r0, #0x10
	strh r0, [r1]
_0809FCAE:
	adds r3, r4, #0
	adds r3, #0x92
	ldrh r0, [r3]
	movs r1, #4
	movs r2, #0
	orrs r1, r0
	strh r1, [r3]
	strb r2, [r6]
	b _0809FCD0
	.align 2, 0
_0809FCC0: .4byte FUN_0809f7fc
_0809FCC4:
	adds r0, r4, #0
	adds r0, #0xf0
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_0809FCD0:
	adds r1, r4, #0
	adds r1, #0xd0
	ldrh r0, [r1]
	cmp r0, #0
	beq _0809FCDE
	subs r0, #1
	strh r0, [r1]
_0809FCDE:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809fce4
FUN_0809fce4: @ 0x0809FCE4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	adds r6, r2, #0
	ldr r2, [sp, #0x18]
	adds r0, #0xe0
	movs r5, #0
	movs r4, #0
	strh r1, [r0]
	subs r0, #4
	strb r3, [r0]
	adds r0, #6
	strh r4, [r0]
	adds r0, #3
	strb r5, [r0]
	subs r0, #6
	strb r5, [r0]
	subs r0, #2
	mov r1, sp
	ldrb r1, [r1, #0x14]
	strb r1, [r0]
	adds r0, #9
	strb r2, [r0]
	lsls r2, r2, #0x18
	cmp r2, #0
	beq _0809FD22
	adds r0, r6, #0
	bl GetMapAreaAt
	adds r1, r7, #0
	adds r1, #0xe8
	strh r0, [r1]
_0809FD22:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_0809fd28
FUN_0809fd28: @ 0x0809FD28
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r4, r7, #0
	adds r4, #0x2c
	ldr r1, _0809FD90 @ =0x0000A680
	adds r0, r4, #0
	bl Video_GetAuxSprite
	adds r0, r7, #0
	adds r1, r4, #0
	movs r2, #0
	bl AuxSprite_Add
	adds r0, r4, #0
	movs r1, #0x43
	bl Video_SetAuxSpritePltt
	movs r0, #3
	strb r0, [r7, #7]
	ldr r0, [r6]
	ldr r1, [r6, #4]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	adds r0, r7, #0
	adds r0, #0xe4
	strb r5, [r0]
	lsls r5, r5, #0x18
	cmp r5, #0
	beq _0809FD86
	adds r4, #0x1c
	subs r0, #4
	ldrh r1, [r0]
	adds r2, r7, #0
	adds r2, #0x1c
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r4, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r4, #0
	bl FUN_08002a48
_0809FD86:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809FD90: .4byte 0x0000A680

	thumb_func_start FUN_0809fd94
FUN_0809fd94: @ 0x0809FD94
	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x8c
	ldr r2, _0809FE0C @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x80
	orrs r0, r3
	ldr r1, _0809FE10 @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r3, sp, #0x14
	ldr r0, [r3, #4]
	ands r0, r2
	str r0, [r3, #4]
	adds r0, r4, #0
	adds r0, #0xe0
	ldrh r1, [r0]
	ldr r2, _0809FE14 @ =0x00004003
	movs r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r3, [sp, #8]
	adds r0, r5, #0
	movs r3, #0
	bl Hitbox_Init
	ldr r1, _0809FE18 @ =FUN_0809f75c
	adds r0, r5, #0
	adds r2, r4, #0
	bl Hitbox_SetHandler
	adds r4, #0x1c
	adds r0, r5, #0
	adds r1, r4, #0
	movs r2, #0
	bl Hitbox_SetPos
	adds r0, r5, #0
	bl Hitbox_Register
	movs r0, #0x96
	lsls r0, r0, #2
	strh r0, [r5, #0x3e]
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0809FE0C: .4byte 0xFFFF0000
_0809FE10: .4byte 0x0000FFFF
_0809FE14: .4byte 0x00004003
_0809FE18: .4byte FUN_0809f75c

	thumb_func_start FUN_0809fe1c
FUN_0809fe1c: @ 0x0809FE1C
	push {lr}
	adds r1, r0, #0
	adds r0, #0xdc
	ldrb r0, [r0]
	cmp r0, #0
	bne _0809FE3C
	strh r0, [r1, #0x10]
	ldr r2, _0809FE38 @ =FUN_0809fabc
	adds r0, r1, #0
	movs r1, #0
	bl FUN_0809f744
	b _0809FE66
	.align 2, 0
_0809FE38: .4byte FUN_0809fabc
_0809FE3C:
	cmp r0, #2
	bne _0809FE54
	movs r0, #8
	strh r0, [r1, #0x10]
	ldr r2, _0809FE50 @ =FUN_0809f8e4
	adds r0, r1, #0
	movs r1, #2
	bl FUN_0809f744
	b _0809FE66
	.align 2, 0
_0809FE50: .4byte FUN_0809f8e4
_0809FE54:
	cmp r0, #1
	bne _0809FE66
	movs r0, #5
	strh r0, [r1, #0x10]
	ldr r2, _0809FE6C @ =FUN_0809f7fc
	adds r0, r1, #0
	movs r1, #1
	bl FUN_0809f744
_0809FE66:
	pop {r0}
	bx r0
	.align 2, 0
_0809FE6C: .4byte FUN_0809f7fc

	thumb_func_start FUN_0809fe70
FUN_0809fe70: @ 0x0809FE70
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #8
	adds r4, r0, #0
	mov r8, r2
	ldr r7, [sp, #0x20]
	ldr r5, [sp, #0x24]
	ldr r6, [sp, #0x28]
	ldrh r2, [r4, #0x18]
	movs r0, #0xf4
	muls r0, r2, r0
	adds r0, #0x1c
	adds r4, r4, r0
	str r5, [sp]
	str r6, [sp, #4]
	adds r0, r4, #0
	mov r2, r8
	bl FUN_0809fce4
	adds r0, r4, #0
	mov r1, r8
	adds r2, r7, #0
	bl FUN_0809fd28
	adds r0, r4, #0
	bl FUN_0809fd94
	adds r0, r4, #0
	bl FUN_0809fe1c
	add sp, #8
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start Entity1DBE_Update
Entity1DBE_Update: @ 0x0809FEBC
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r5, #0
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	bge _0809FEDC
	adds r4, r6, #0
	adds r4, #0x1c
_0809FECC:
	adds r0, r4, #0
	bl FUN_0809fbf8
	adds r4, #0xf4
	adds r5, #1
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	blt _0809FECC
_0809FEDC:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start Entity1DBE_Destroy
Entity1DBE_Destroy: @ 0x0809FEE4
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	b _0809FF1C
_0809FEEC:
	movs r0, #0xf4
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r5, r4
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809FF08
	adds r0, r4, r5
	adds r0, #0x64
	bl FUN_0823b284
_0809FF08:
	adds r4, #0x1c
	adds r4, r5, r4
	adds r0, r4, #0
	bl AuxSprite_Remove
	adds r4, #0x8c
	adds r0, r4, #0
	bl Hitbox_Unregister
	adds r6, #1
_0809FF1C:
	ldrh r0, [r5, #0x18]
	cmp r6, r0
	blt _0809FEEC
	ldr r1, _0809FF30 @ =0x03000144
	movs r0, #0
	str r0, [r1]
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_0809FF30: .4byte 0x03000144

	thumb_func_start Entity1DBE_Init
Entity1DBE_Init: @ 0x0809FF34
	movs r1, #0
	strh r1, [r0, #0x18]
	ldr r1, _0809FF40 @ =0x03000144
	str r0, [r1]
	movs r0, #0
	bx lr
	.align 2, 0
_0809FF40: .4byte 0x03000144

	thumb_func_start Entity1DBE_Create
Entity1DBE_Create: @ 0x0809FF44
	push {r4, lr}
	ldr r1, _0809FF70 @ =0x000007BC
	movs r0, #9
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809FF7C
	ldr r1, _0809FF74 @ =Entity1DBE_Update
	ldr r2, _0809FF78 @ =Entity1DBE_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity1DBE_Init
	cmp r0, #0
	bge _0809FF7C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809FF7E
	.align 2, 0
_0809FF70: .4byte 0x000007BC
_0809FF74: .4byte Entity1DBE_Update
_0809FF78: .4byte Entity1DBE_Destroy
_0809FF7C:
	adds r0, r4, #0
_0809FF7E:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_0809ff84
FUN_0809ff84: @ 0x0809FF84
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	ldr r0, _0809FFB0 @ =0x03000144
	ldr r6, [r0]
	cmp r6, #0
	bne _0809FF9A
	bl Entity1DBE_Create
	adds r6, r0, #0
_0809FF9A:
	ldrh r0, [r6, #0x18]
	cmp r0, #7
	bhi _080A0074
	movs r0, #0x6e
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _0809FFB4
	bl VM_GetValue
	b _0809FFB6
	.align 2, 0
_0809FFB0: .4byte 0x03000144
_0809FFB4:
	movs r0, #0
_0809FFB6:
	mov r8, r0
	movs r0, #0x70
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A0000
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r4, _0809FFF8 @ =0xFFFF0000
	ldr r1, [sp, #0xc]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0xc]
	bl VM_GetValue
	lsls r0, r0, #0x10
	ldr r2, _0809FFFC @ =0x0000FFFF
	ldr r1, [sp, #0xc]
	ands r1, r2
	orrs r1, r0
	str r1, [sp, #0xc]
	bl VM_GetValue
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r1, [sp, #0x10]
	ands r1, r4
	orrs r1, r0
	str r1, [sp, #0x10]
	b _080A000A
	.align 2, 0
_0809FFF8: .4byte 0xFFFF0000
_0809FFFC: .4byte 0x0000FFFF
_080A0000:
	ldr r1, _080A001C @ =0xFFFF0000
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r1
	str r0, [sp, #0x10]
_080A000A:
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A0020
	bl VM_GetValue
	adds r7, r0, #0
	b _080A0022
	.align 2, 0
_080A001C: .4byte 0xFFFF0000
_080A0020:
	movs r7, #0
_080A0022:
	movs r0, #0x68
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A0034
	bl VM_GetValue
	adds r5, r0, #0
	b _080A0036
_080A0034:
	movs r5, #0
_080A0036:
	movs r0, #0x66
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A0048
	bl VM_GetValue
	adds r4, r0, #0
	b _080A004A
_080A0048:
	movs r4, #0
_080A004A:
	movs r0, #0x6d
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _080A005A
	bl VM_GetValue
	b _080A005C
_080A005A:
	movs r0, #0
_080A005C:
	str r5, [sp]
	str r4, [sp, #4]
	str r0, [sp, #8]
	adds r0, r6, #0
	mov r1, r8
	add r2, sp, #0xc
	adds r3, r7, #0
	bl FUN_0809fe70
	ldrh r0, [r6, #0x18]
	adds r0, #1
	strh r0, [r6, #0x18]
_080A0074:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
