	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_080a8804
FUN_080a8804: @ 0x080A8804
	adds r2, r0, #0
	movs r3, #0xee
	lsls r3, r3, #1
	adds r0, r2, r3
	str r1, [r0]
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r2, r0
	movs r0, #0
	strh r0, [r1]
	bx lr
	.align 2, 0

	thumb_func_start FUN_080a881c
FUN_080a881c: @ 0x080A881C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	adds r5, r0, #0
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080A8870
	adds r4, r5, #0
	adds r4, #0x6c
	movs r1, #0xd0
	lsls r1, r1, #1
	adds r6, r5, r1
_080A8848:
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	adds r0, r5, #0
	ldr r1, _080A886C @ =FUN_080a8950
	bl FUN_080a8804
	adds r4, #0x2c
	cmp r4, r6
	ble _080A8848
	ldr r0, [r5, #0x1c]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x1c]
	b _080A8940
	.align 2, 0
_080A886C: .4byte FUN_080a8950
_080A8870:
	ldrh r1, [r1]
	movs r0, #0x20
	subs r6, r0, r1
	adds r2, r6, #1
	str r2, [sp]
	adds r0, r5, #0
	adds r0, #0x64
	str r0, [sp, #4]
	movs r1, #0x66
	adds r1, r1, r5
	mov sl, r1
	movs r2, #0x68
	adds r2, r2, r5
	mov sb, r2
	ldr r0, _080A88C8 @ =0x085B0A08
	mov r8, r0
	adds r4, r5, #0
	adds r4, #0x6c
	movs r7, #7
_080A8896:
	ldrh r0, [r4, #0x28]
	adds r0, #4
	movs r1, #0xff
	ands r0, r1
	strh r0, [r4, #0x28]
	ldrh r0, [r4, #0x2a]
	muls r0, r6, r0
	ldr r1, [sp]
	bl Div
	strh r0, [r4, #0x2a]
	ldrh r2, [r4, #0x2a]
	ldrh r0, [r4, #0x28]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A88CC
	asrs r2, r0, #0xc
	b _080A88D2
	.align 2, 0
_080A88C8: .4byte 0x085B0A08
_080A88CC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A88D2:
	ldr r1, [sp, #4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r4, #0x18]
	movs r2, #0xed
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	movs r1, #0x1e
	subs r1, r1, r0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	mov r1, sl
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
	ldrh r2, [r4, #0x2a]
	ldrh r1, [r4, #0x28]
	movs r0, #0xff
	ands r0, r1
	lsls r0, r0, #1
	add r0, r8
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A890E
	asrs r2, r0, #0xc
	b _080A8914
_080A890E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A8914:
	mov r1, sb
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r4, #0x1c]
	movs r2, #0xed
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #8
	bne _080A8938
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r4, #0
	movs r2, #6
	bl FUN_0822dafc
_080A8938:
	adds r4, #0x2c
	subs r7, #1
	cmp r7, #0
	bge _080A8896
_080A8940:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a8950
FUN_080a8950: @ 0x080A8950
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x18
	adds r6, r0, #0
	ldr r0, _080A897C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A898E
	ldr r0, [r6, #0x18]
	ldr r1, [r0, #0x18]
	ldr r0, _080A8980 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080A8984
	movs r0, #0
	b _080A898A
	.align 2, 0
_080A897C: .4byte 0x030047A4
_080A8980: .4byte 0x03002C68
_080A8984:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080A898A:
	adds r7, r0, #0
	b _080A899A
_080A898E:
	ldr r0, _080A89B8 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _080A89BC @ =0x00000942
	adds r0, r0, r1
	movs r2, #0
	ldrsh r7, [r0, r2]
_080A899A:
	movs r3, #0xea
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r1, [r2]
	cmp r1, #0
	beq _080A89D8
	subs r3, #4
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A89C0
	subs r0, r1, #1
	strh r0, [r2]
	b _080A89D8
	.align 2, 0
_080A89B8: .4byte 0x030046A0
_080A89BC: .4byte 0x00000942
_080A89C0:
	cmp r7, #0
	ble _080A89C8
	subs r0, r1, #1
	strh r0, [r2]
_080A89C8:
	movs r0, #0xeb
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _080A89D8
	subs r0, #1
	strh r0, [r1]
_080A89D8:
	adds r0, r6, #0
	adds r0, #0x64
	ldrh r1, [r0]
	lsls r1, r1, #0x10
	asrs r2, r1, #0x18
	ldrh r1, [r0, #4]
	lsls r1, r1, #0x10
	asrs r1, r1, #0x18
	mov sb, r0
	cmp r2, #0
	blt _080A8A02
	cmp r1, #0
	blt _080A8A02
	ldr r0, _080A8A08 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A8A02
	ldr r0, _080A8A0C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A8A10
_080A8A02:
	movs r4, #0
	b _080A8A1E
	.align 2, 0
_080A8A08: .4byte 0x030046A8
_080A8A0C: .4byte 0x030046AC
_080A8A10:
	ldr r0, _080A8A30 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A8A1E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A8A34
	adds r0, #4
	b _080A8A40
	.align 2, 0
_080A8A30: .4byte 0x030046A4
_080A8A34:
	ldr r0, _080A8A54 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A8A40:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080A8A5C
	ldr r1, _080A8A58 @ =FUN_080a8cfc
	adds r0, r6, #0
	bl FUN_080a8804
	b _080A8B14
	.align 2, 0
_080A8A54: .4byte 0x030046A4
_080A8A58: .4byte FUN_080a8cfc
_080A8A5C:
	mov r5, sb
	ldrh r0, [r5]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080A8A82
	cmp r1, #0
	blt _080A8A82
	ldr r0, _080A8A88 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080A8A82
	ldr r0, _080A8A8C @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080A8A90
_080A8A82:
	movs r4, #0
	b _080A8A9E
	.align 2, 0
_080A8A88: .4byte 0x030046A8
_080A8A8C: .4byte 0x030046AC
_080A8A90:
	ldr r0, _080A8AB0 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080A8A9E:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080A8AB4
	adds r0, #4
	b _080A8AC0
	.align 2, 0
_080A8AB0: .4byte 0x030046A4
_080A8AB4:
	ldr r0, _080A8AD4 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080A8AC0:
	ldrb r1, [r0]
	lsrs r2, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r1, r0, #8
	cmp r2, #1
	beq _080A8AD8
	cmp r2, #2
	beq _080A8ADC
	b _080A8AE0
	.align 2, 0
_080A8AD4: .4byte 0x030046A4
_080A8AD8:
	ldrb r0, [r5, #4]
	b _080A8ADE
_080A8ADC:
	ldrb r0, [r5]
_080A8ADE:
	subs r1, r1, r0
_080A8AE0:
	adds r2, r6, #0
	adds r2, #0x66
	movs r3, #0
	ldrsh r0, [r2, r3]
	cmp r1, r0
	ble _080A8AF8
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	b _080A8B14
_080A8AF8:
	cmp r1, r0
	bge _080A8B14
	ldrh r0, [r2]
	subs r0, #0x1e
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	cmp r0, r1
	bge _080A8B0C
	strh r1, [r2]
_080A8B0C:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [r6, #0x38]
	str r1, [r6, #0x3c]
_080A8B14:
	movs r2, #0xea
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r3, #0xe9
	lsls r3, r3, #1
	adds r2, r6, r3
	ldrh r0, [r1]
	ldrh r3, [r2]
	cmp r0, r3
	bhs _080A8B38
	movs r1, #0xed
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, #0x14
	b _080A8B60
_080A8B38:
	ldrh r1, [r1]
	ldrh r0, [r2]
	lsls r0, r0, #1
	cmp r1, r0
	bge _080A8B52
	movs r2, #0xed
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, #0x10
	b _080A8B60
_080A8B52:
	movs r3, #0xed
	lsls r3, r3, #1
	adds r0, r6, r3
	ldrh r1, [r0]
	movs r0, #3
	ands r0, r1
	adds r0, #0xc
_080A8B60:
	strh r0, [r6, #0x2c]
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r6, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A8B7C
	b _080A8CC8
_080A8B7C:
	movs r2, #0xe8
	lsls r2, r2, #1
	adds r0, r6, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080A8B8C
	movs r3, #0x7d
	b _080A8BCE
_080A8B8C:
	ldr r0, _080A8BB4 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A8BBC
	ldr r0, [r6, #0x18]
	ldr r1, _080A8BB8 @ =0x0000035E
	adds r0, r0, r1
	ldrh r0, [r0]
	lsls r1, r0, #1
	adds r1, r1, r0
	lsls r0, r7, #2
	adds r0, r0, r7
	lsls r0, r0, #1
	adds r1, r1, r0
	mov r8, r1
	b _080A8BD0
	.align 2, 0
_080A8BB4: .4byte 0x030047A4
_080A8BB8: .4byte 0x0000035E
_080A8BBC:
	ldr r0, [r6, #0x18]
	ldr r2, _080A8C24 @ =0x0000035E
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #0xa
	bl Div
	adds r3, r0, #0
	muls r3, r7, r3
_080A8BCE:
	mov r8, r3
_080A8BD0:
	movs r5, #0
	movs r0, #0x68
	adds r0, r0, r6
	mov sl, r0
	add r4, sp, #0x10
	ldr r7, _080A8C28 @ =0xFFFF0000
_080A8BDC:
	ldr r0, [r6, #0x64]
	ldr r1, [r6, #0x68]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldr r1, [sp, #0x10]
	asrs r0, r1, #0x10
	adds r0, #0x80
	lsls r0, r0, #0x10
	ldr r2, _080A8C2C @ =0x0000FFFF
	ands r2, r1
	orrs r2, r0
	str r2, [sp, #0x10]
	ldrh r1, [r4]
	adds r1, #0x40
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	ldrh r0, [r4, #4]
	adds r0, #0x40
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	ldr r2, [r4, #4]
	ands r2, r7
	orrs r2, r0
	str r2, [r4, #4]
	cmp r5, #2
	beq _080A8C40
	cmp r5, #2
	bgt _080A8C30
	cmp r5, #1
	beq _080A8C3A
	b _080A8C68
	.align 2, 0
_080A8C24: .4byte 0x0000035E
_080A8C28: .4byte 0xFFFF0000
_080A8C2C: .4byte 0x0000FFFF
_080A8C30:
	cmp r5, #3
	beq _080A8C46
	cmp r5, #4
	beq _080A8C58
	b _080A8C68
_080A8C3A:
	ldrh r1, [r4]
	adds r1, #0x60
	b _080A8C5C
_080A8C40:
	ldrh r1, [r4, #4]
	adds r1, #0x60
	b _080A8C4A
_080A8C46:
	ldrh r1, [r4, #4]
	subs r1, #0x60
_080A8C4A:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	adds r0, r7, #0
	ands r0, r2
	orrs r0, r1
	str r0, [r4, #4]
	b _080A8C68
_080A8C58:
	ldrh r1, [r4]
	subs r1, #0x60
_080A8C5C:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r0, [sp, #0x10]
	ands r0, r7
	orrs r0, r1
	str r0, [sp, #0x10]
_080A8C68:
	ldr r0, _080A8CBC @ =0x00241004
	str r0, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	lsls r0, r5, #2
	str r0, [sp, #0xc]
	add r0, sp, #0x10
	movs r1, #0
	mov r2, r8
	movs r3, #0x32
	bl FUN_080d85d8
	adds r5, #1
	cmp r5, #4
	ble _080A8BDC
	mov r1, sb
	movs r2, #0
	ldrsh r0, [r1, r2]
	mov r3, sl
	movs r2, #0
	ldrsh r1, [r3, r2]
	movs r2, #0x80
	lsls r2, r2, #3
	movs r3, #1
	str r3, [sp]
	ldr r3, _080A8CC0 @ =0x0000B546
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	ldr r1, [r6, #0x18]
	ldr r3, _080A8CC4 @ =0x000003FB
	adds r1, r1, r3
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl KillEntity
	b _080A8CE6
	.align 2, 0
_080A8CBC: .4byte 0x00241004
_080A8CC0: .4byte 0x0000B546
_080A8CC4: .4byte 0x000003FB
_080A8CC8:
	movs r1, #0xeb
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A8CE6
	ldr r1, [r6, #0x18]
	ldr r2, _080A8CF8 @ =0x000003FB
	adds r1, r1, r2
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r6, #0
	bl KillEntity
_080A8CE6:
	add sp, #0x18
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A8CF8: .4byte 0x000003FB

	thumb_func_start FUN_080a8cfc
FUN_080a8cfc: @ 0x080A8CFC
	push {lr}
	adds r2, r0, #0
	adds r1, r2, #0
	adds r1, #0x66
	ldrh r0, [r1]
	subs r0, #0x14
	strh r0, [r1]
	ldr r0, [r2, #0x64]
	ldr r1, [r2, #0x68]
	str r0, [r2, #0x38]
	str r1, [r2, #0x3c]
	movs r0, #0xed
	lsls r0, r0, #1
	adds r1, r2, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #2
	bls _080A8D38
	ldr r1, [r2, #0x18]
	ldr r0, _080A8D3C @ =0x000003FB
	adds r1, r1, r0
	ldrb r0, [r1]
	subs r0, #1
	strb r0, [r1]
	adds r0, r2, #0
	bl KillEntity
_080A8D38:
	pop {r0}
	bx r0
	.align 2, 0
_080A8D3C: .4byte 0x000003FB

	thumb_func_start FUN_080a8d40
FUN_080a8d40: @ 0x080A8D40
	push {lr}
	movs r2, #0xee
	lsls r2, r2, #1
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start FUN_080a8d54
FUN_080a8d54: @ 0x080A8D54
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl FUN_0822a4e0
	adds r4, #0x6c
	movs r5, #7
_080A8D62:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080A8D62
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a8d78
FUN_080a8d78: @ 0x080A8D78
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x48
	ldr r1, _080A8DC4 @ =0x0000E74B
	adds r0, r6, #0
	bl Video_GetActorSprite
	adds r4, r5, #0
	adds r4, #0x1c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #1
	bl FUN_0822a470
	movs r0, #0xc
	strh r0, [r4, #0x10]
	ldr r0, [r5, #0x64]
	ldr r1, [r5, #0x68]
	str r0, [r5, #0x38]
	str r1, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x38
	movs r1, #0x80
	bl FUN_082342cc
	cmp r0, #0
	beq _080A8DC8
	movs r1, #0x99
	lsls r1, r1, #1
	adds r0, r6, #0
	bl FUN_0822b20c
	adds r1, r5, #0
	adds r1, #0x23
	movs r0, #1
	b _080A8DCE
	.align 2, 0
_080A8DC4: .4byte 0x0000E74B
_080A8DC8:
	adds r1, r5, #0
	adds r1, #0x23
	movs r0, #2
_080A8DCE:
	strb r0, [r1]
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a8dd8
FUN_080a8dd8: @ 0x080A8DD8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r6, _080A8EBC @ =0x0203B400
	ldr r4, _080A8EC0 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080A8EC4 @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	str r0, [sp]
	ldr r0, _080A8EC8 @ =0x00001C1E
	bl GetParticleGroup
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	movs r0, #0
	mov r8, r0
	adds r1, r2, #0
	adds r1, r1, r7
	mov sb, r1
	mov sl, r5
	ldr r6, _080A8ECC @ =0x085B0A08
_080A8E18:
	movs r0, #0x2c
	mov r4, r8
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0x6c
	adds r5, r7, r0
	mov r2, sb
	ldr r1, [r2]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	mov r0, sb
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #7
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	ldr r1, _080A8EC0 @ =0x030046B8
	ldr r2, [r1]
	adds r2, #1
	mov r0, sl
	ands r2, r0
	lsls r0, r2, #1
	ldr r1, _080A8EBC @ =0x0203B400
	adds r0, r0, r1
	ldrh r3, [r0]
	adds r4, r7, r4
	mov r1, r8
	lsls r0, r1, #5
	ldr r1, [sp]
	adds r0, r1, r0
	movs r1, #0xf
	ands r3, r1
	adds r0, r0, r3
	movs r1, #0xff
	ands r0, r1
	adds r3, r4, #0
	adds r3, #0x94
	strh r0, [r3]
	adds r2, #1
	mov r0, sl
	ands r2, r0
	ldr r1, _080A8EC0 @ =0x030046B8
	str r2, [r1]
	lsls r2, r2, #1
	ldr r0, _080A8EBC @ =0x0203B400
	adds r2, r2, r0
	ldrh r1, [r2]
	ldr r2, _080A8ED0 @ =0x000001FF
	adds r0, r2, #0
	ands r1, r0
	movs r0, #0x80
	lsls r0, r0, #1
	adds r1, r1, r0
	adds r4, #0x96
	strh r1, [r4]
	ldrh r2, [r4]
	ldrh r0, [r3]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A8ED4
	asrs r2, r0, #0xc
	b _080A8EDA
	.align 2, 0
_080A8EBC: .4byte 0x0203B400
_080A8EC0: .4byte 0x030046B8
_080A8EC4: .4byte 0x000003FF
_080A8EC8: .4byte 0x00001C1E
_080A8ECC: .4byte 0x085B0A08
_080A8ED0: .4byte 0x000001FF
_080A8ED4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A8EDA:
	adds r0, r7, #0
	adds r0, #0x64
	ldrh r0, [r0]
	adds r0, r0, r2
	strh r0, [r5, #0x18]
	adds r1, r7, #0
	adds r1, #0x66
	movs r2, #0x96
	lsls r2, r2, #1
	adds r0, r2, #0
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r5, #0x1a]
	movs r0, #0x2c
	mov r1, r8
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, r7, r0
	adds r1, r0, #0
	adds r1, #0x96
	ldrh r1, [r1]
	adds r0, #0x94
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r6
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A8F1A
	asrs r1, r0, #0xc
	b _080A8F20
_080A8F1A:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A8F20:
	adds r0, r7, #0
	adds r0, #0x68
	ldrh r0, [r0]
	adds r0, r0, r1
	strh r0, [r5, #0x1c]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0xec
	strb r0, [r5, #0x10]
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #7
	bgt _080A8F3E
	b _080A8E18
_080A8F3E:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a8f50
FUN_080a8f50: @ 0x080A8F50
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r4, [r2]
	ldr r5, [r2, #4]
	str r4, [r6, #0x64]
	str r5, [r6, #0x68]
	str r1, [r6, #0x18]
	movs r0, #0xe8
	lsls r0, r0, #1
	adds r4, r6, r0
	strh r3, [r4]
	adds r0, r6, #0
	bl FUN_080a8d78
	adds r0, r6, #0
	bl FUN_080a8dd8
	ldr r1, [r6, #0x18]
	ldr r2, _080A8F90 @ =0x000003FB
	adds r1, r1, r2
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
	ldrh r0, [r4]
	cmp r0, #0
	beq _080A8F94
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0x78
	b _080A8FB8
	.align 2, 0
_080A8F90: .4byte 0x000003FB
_080A8F94:
	ldr r0, _080A8FAC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #4
	ands r0, r1
	cmp r0, #0
	beq _080A8FB0
	movs r2, #0xea
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x5a
	b _080A8FB8
	.align 2, 0
_080A8FAC: .4byte 0x030047A4
_080A8FB0:
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0xb4
_080A8FB8:
	strh r0, [r1]
	movs r1, #0xea
	lsls r1, r1, #1
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r1, #3
	bl Div
	movs r2, #0xe9
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r0, #0xeb
	lsls r0, r0, #1
	adds r1, r6, r0
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, #0x15
	bl PlaySound_082406e0
	ldr r1, _080A8FF4 @ =FUN_080a881c
	adds r0, r6, #0
	bl FUN_080a8804
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080A8FF4: .4byte FUN_080a881c

	thumb_func_start FUN_080a8ff8
FUN_080a8ff8: @ 0x080A8FF8
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	adds r7, r2, #0
	movs r1, #0xf0
	lsls r1, r1, #1
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A903C
	ldr r1, _080A9034 @ =0x080A8D41
	ldr r2, _080A9038 @ =FUN_080a8d54
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	adds r3, r7, #0
	bl FUN_080a8f50
	cmp r0, #0
	bge _080A903C
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A903E
	.align 2, 0
_080A9034: .4byte 0x080A8D41
_080A9038: .4byte FUN_080a8d54
_080A903C:
	adds r0, r4, #0
_080A903E:
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a9044
FUN_080a9044: @ 0x080A9044
	movs r3, #0x80
	lsls r3, r3, #2
	adds r2, r0, r3
	str r1, [r2]
	movs r1, #0xff
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r1, #0
	strh r1, [r0]
	bx lr

	thumb_func_start FUN_080a9058
FUN_080a9058: @ 0x080A9058
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r0, #0
	mov sl, r0
	movs r1, #0xff
	lsls r1, r1, #1
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0xb
	bhi _080A907C
	adds r0, r5, #0
	adds r0, #0x24
	bl FUN_08236400
_080A907C:
	movs r2, #0xff
	lsls r2, r2, #1
	adds r2, r2, r5
	mov r8, r2
	movs r7, #0
	adds r6, r5, #0
	adds r6, #0x74
	adds r4, r5, #0
	adds r4, #0x8c
	movs r0, #7
	mov sb, r0
_080A9092:
	mov r1, r8
	ldrh r0, [r1]
	ldrb r2, [r4, #0x15]
	cmp r0, r2
	blo _080A90AC
	adds r0, r5, #0
	adds r0, #0x74
	adds r0, r0, r7
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _080A9170
_080A90AC:
	movs r0, #1
	mov sl, r0
	ldrb r0, [r4, #0x14]
	ldrb r1, [r4, #0x10]
	adds r0, r0, r1
	strb r0, [r4, #0x10]
	ldrh r3, [r4, #0x16]
	ldr r2, _080A90D8 @ =0x085B0A08
	ldrb r0, [r4, #0x10]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080A90DC
	asrs r3, r0, #0xc
	b _080A90E2
	.align 2, 0
_080A90D8: .4byte 0x085B0A08
_080A90DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_080A90E2:
	ldrh r0, [r5, #0x1c]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r1, [r4, #0x16]
	ldrb r0, [r4, #0x10]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A90FE
	asrs r1, r0, #0xc
	b _080A9104
_080A90FE:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A9104:
	ldrh r0, [r5, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #4]
	mov r0, r8
	ldrh r1, [r0]
	ldrb r2, [r4, #0x12]
	cmp r1, r2
	blo _080A912E
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080A9126
	ldrb r0, [r4, #0x14]
	cmp r0, #2
	bls _080A9126
	subs r0, #1
	strb r0, [r4, #0x14]
_080A9126:
	ldrh r0, [r4, #2]
	ldrb r1, [r4, #0x11]
	adds r0, r0, r1
	strh r0, [r4, #2]
_080A912E:
	ldrb r0, [r4, #0x13]
	cmp r0, #0
	bne _080A9146
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r1, [r0]
	adds r0, r6, #0
	movs r2, #0xc
	bl FUN_0822dafc
	b _080A915E
_080A9146:
	cmp r0, #4
	bne _080A915E
	adds r0, r7, #0
	adds r0, #0x74
	adds r0, r5, r0
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r5, r2
	ldr r1, [r1]
	movs r2, #0xd
	bl FUN_0822dafc
_080A915E:
	ldrb r0, [r4, #0x13]
	adds r0, #1
	movs r1, #0
	strb r0, [r4, #0x13]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #7
	bls _080A9170
	strb r1, [r4, #0x13]
_080A9170:
	adds r7, #0x30
	adds r6, #0x30
	adds r4, #0x30
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _080A9092
	movs r2, #0xff
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	mov r0, sl
	cmp r0, #0
	bne _080A919A
	adds r0, r5, #0
	bl KillEntity
_080A919A:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start HealingParticles_Update
HealingParticles_Update: @ 0x080A91A8
	push {lr}
	movs r2, #0x80
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r1, [r1]
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

	thumb_func_start HealingParticles_Destroy
HealingParticles_Destroy: @ 0x080A91BC
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x74
	movs r5, #7
_080A91C4:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x30
	subs r5, #1
	cmp r5, #0
	bge _080A91C4
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a91dc
FUN_080a91dc: @ 0x080A91DC
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r6, _080A92C4 @ =0x0203B400
	ldr r4, _080A92C8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080A92CC @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrb r0, [r0]
	str r0, [sp]
	ldr r0, _080A92D0 @ =0x00001C1E
	bl GetParticleGroup
	movs r2, #0xfa
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	movs r3, #0
	mov sb, r3
	adds r6, r4, #0
	mov r8, r5
	movs r0, #0xf
	mov sl, r0
	adds r4, r7, #0
	adds r4, #0x84
	adds r5, r7, #0
	adds r5, #0x74
_080A9222:
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0
	bl FUN_0822d9f0
	movs r2, #4
	rsbs r2, r2, #0
	adds r0, r5, #0
	adds r1, r2, #0
	bl FUN_0822dad4
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	ldr r2, [r6]
	adds r2, #1
	mov r3, r8
	ands r2, r3
	lsls r0, r2, #1
	ldr r1, _080A92C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r1, [r0]
	mov r3, sb
	lsls r0, r3, #5
	ldr r3, [sp]
	adds r0, r3, r0
	mov r3, sl
	ands r1, r3
	adds r0, r0, r1
	strb r0, [r4, #0x18]
	movs r1, #3
	mov r0, sb
	ands r0, r1
	lsls r0, r0, #1
	adds r0, #3
	strb r0, [r4, #0x19]
	adds r2, #1
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	ldr r1, _080A92C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x1f
	ands r0, r1
	adds r0, #0x40
	strh r0, [r4, #0x1e]
	adds r2, #1
	mov r3, r8
	ands r2, r3
	str r2, [r6]
	lsls r2, r2, #1
	ldr r0, _080A92C4 @ =0x0203B400
	adds r2, r2, r0
	ldrh r0, [r2]
	mov r1, sl
	ands r0, r1
	adds r0, #0xc
	strb r0, [r4, #0x1a]
	movs r0, #7
	strb r0, [r4, #0x1c]
	ldrh r2, [r4, #0x1e]
	ldrb r0, [r4, #0x18]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	ldr r3, _080A92D4 @ =0x085B0A08
	adds r0, r0, r3
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r2, r0
	cmp r0, #0
	blt _080A92D8
	asrs r2, r0, #0xc
	b _080A92DE
	.align 2, 0
_080A92C4: .4byte 0x0203B400
_080A92C8: .4byte 0x030046B8
_080A92CC: .4byte 0x000003FF
_080A92D0: .4byte 0x00001C1E
_080A92D4: .4byte 0x085B0A08
_080A92D8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080A92DE:
	ldrh r0, [r7, #0x1c]
	adds r0, r0, r2
	strh r0, [r4, #8]
	ldrh r0, [r7, #0x1e]
	strh r0, [r4, #0xa]
	ldrh r1, [r4, #0x1e]
	ldrb r0, [r4, #0x18]
	lsls r0, r0, #1
	ldr r2, _080A9300 @ =0x085B0A08
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A9304
	asrs r1, r0, #0xc
	b _080A930A
	.align 2, 0
_080A9300: .4byte 0x085B0A08
_080A9304:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080A930A:
	ldrh r0, [r7, #0x20]
	adds r0, r0, r1
	strh r0, [r4, #0xc]
	movs r0, #2
	strb r0, [r5, #0xf]
	movs r0, #0xec
	strb r0, [r4]
	ldr r0, [r6]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r6]
	lsls r0, r0, #1
	ldr r2, _080A9348 @ =0x0203B400
	adds r0, r0, r2
	ldrh r1, [r0]
	movs r0, #7
	ands r1, r0
	strb r1, [r4, #0x1b]
	cmp r1, #3
	bhi _080A934C
	movs r3, #0xfa
	lsls r3, r3, #1
	adds r0, r7, r3
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0xc
	bl FUN_0822dafc
	b _080A935C
	.align 2, 0
_080A9348: .4byte 0x0203B400
_080A934C:
	movs r1, #0xfa
	lsls r1, r1, #1
	adds r0, r7, r1
	ldr r1, [r0]
	adds r0, r5, #0
	movs r2, #0xd
	bl FUN_0822dafc
_080A935C:
	ldr r0, [r6]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r6]
	lsls r0, r0, #1
	ldr r3, _080A9398 @ =0x0203B400
	adds r0, r0, r3
	ldrh r0, [r0]
	mov r1, sl
	ands r0, r1
	adds r0, #0x38
	strb r0, [r4, #0x1d]
	adds r4, #0x30
	adds r5, #0x30
	movs r2, #1
	add sb, r2
	mov r3, sb
	cmp r3, #7
	bgt _080A9386
	b _080A9222
_080A9386:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9398: .4byte 0x0203B400

	thumb_func_start FUN_080a939c
FUN_080a939c: @ 0x080A939C
	push {r4, r5, r6, lr}
	sub sp, #0x1c
	adds r5, r0, #0
	adds r6, r5, #0
	adds r6, #0x24
	ldr r2, _080A9418 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x64
	orrs r0, r3
	ldr r1, _080A941C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0xc8
	lsls r1, r1, #0xe
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r4, #0
	str r4, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0x80
	lsls r2, r2, #6
	movs r0, #1
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	movs r3, #0x80
	lsls r3, r3, #8
	str r4, [sp]
	str r4, [sp, #4]
	adds r0, r6, #0
	movs r1, #0
	movs r2, #0
	bl FUN_082364f8
	adds r0, r6, #0
	movs r1, #0
	adds r2, r5, #0
	bl FUN_0823651c
	adds r5, #0x1c
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9418: .4byte 0xFFFF0000
_080A941C: .4byte 0x0000FFFF

	thumb_func_start HealingParticles_Init
HealingParticles_Init: @ 0x080A9420
	push {r4, lr}
	adds r4, r0, #0
	ldr r3, [r2, #4]
	ldr r2, [r2]
	str r2, [r4, #0x1c]
	str r3, [r4, #0x20]
	str r1, [r4, #0x18]
	bl FUN_080a91dc
	adds r0, r4, #0
	bl FUN_080a939c
	movs r0, #0xfd
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0xb4
	strh r0, [r1]
	movs r1, #3
	bl Div
	movs r2, #0xfc
	lsls r2, r2, #1
	adds r1, r4, r2
	strh r0, [r1]
	movs r0, #0xfe
	lsls r0, r0, #1
	adds r1, r4, r0
	movs r0, #0xe1
	lsls r0, r0, #2
	strh r0, [r1]
	adds r0, #0x13
	bl PlaySound_082406e0
	ldr r1, _080A9474 @ =FUN_080a9058
	adds r0, r4, #0
	bl FUN_080a9044
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A9474: .4byte FUN_080a9058

	thumb_func_start HealingParticles_Create
HealingParticles_Create: @ 0x080A9478
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0x81
	lsls r1, r1, #2
	movs r0, #8
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A94B8
	ldr r1, _080A94B0 @ =HealingParticles_Update
	ldr r2, _080A94B4 @ =HealingParticles_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl HealingParticles_Init
	cmp r0, #0
	bge _080A94B8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A94BA
	.align 2, 0
_080A94B0: .4byte HealingParticles_Update
_080A94B4: .4byte HealingParticles_Destroy
_080A94B8:
	adds r0, r4, #0
_080A94BA:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a94c0
FUN_080a94c0: @ 0x080A94C0
	push {lr}
	ldr r0, _080A94D0 @ =0x03002C50
	ldr r0, [r0]
	cmp r0, #0
	beq _080A94D4
	ldrh r0, [r0, #0x18]
	b _080A94D6
	.align 2, 0
_080A94D0: .4byte 0x03002C50
_080A94D4:
	movs r0, #0
_080A94D6:
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a94dc
FUN_080a94dc: @ 0x080A94DC
	push {lr}
	ldr r0, _080A94F0 @ =0x03002C50
	ldr r1, [r0]
	cmp r1, #0
	beq _080A94EA
	movs r0, #1
	strh r0, [r1, #0x1a]
_080A94EA:
	pop {r0}
	bx r0
	.align 2, 0
_080A94F0: .4byte 0x03002C50

	thumb_func_start Entity4063_Update
Entity4063_Update: @ 0x080A94F4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x1a]
	cmp r0, #0
	beq _080A950A
	bl FUN_0809c58c
	adds r0, r4, #0
	bl KillEntity
	b _080A952C
_080A950A:
	ldrh r0, [r4, #0x18]
	subs r0, #1
	strh r0, [r4, #0x18]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A952C
	bl FUN_0809c58c
	ldr r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A9526
	movs r1, #0
	bl Script_ExecById
_080A9526:
	adds r0, r4, #0
	bl KillEntity
_080A952C:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start Entity4063_Destroy
Entity4063_Destroy: @ 0x080A9534
	ldr r1, _080A953C @ =0x03002C50
	movs r0, #0
	str r0, [r1]
	bx lr
	.align 2, 0
_080A953C: .4byte 0x03002C50

	thumb_func_start Entity4063_Init
Entity4063_Init: @ 0x080A9540
	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x74
	bl prepare_08231510
	cmp r0, #0
	beq _080A9554
	bl Script_GetValue
	b _080A9558
_080A9554:
	movs r0, #0xe1
	lsls r0, r0, #3
_080A9558:
	strh r0, [r4, #0x18]
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080A9568
	bl Script_GetValue
_080A9568:
	str r0, [r4, #0x1c]
	adds r0, r4, #0
	adds r0, #0x18
	bl FUN_0809c544
	ldr r0, _080A9580 @ =0x03002C50
	str r4, [r0]
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A9580: .4byte 0x03002C50

	thumb_func_start Entity4063_Create
Entity4063_Create: @ 0x080A9584
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r0, _080A95C0 @ =0x03002C50
	ldr r0, [r0]
	cmp r0, #0
	bne _080A95CE
	movs r0, #8
	movs r1, #0x20
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A95CC
	ldr r1, _080A95C4 @ =Entity4063_Update
	ldr r2, _080A95C8 @ =Entity4063_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl Entity4063_Init
	cmp r0, #0
	bge _080A95CC
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A95CE
	.align 2, 0
_080A95C0: .4byte 0x03002C50
_080A95C4: .4byte Entity4063_Update
_080A95C8: .4byte Entity4063_Destroy
_080A95CC:
	adds r0, r4, #0
_080A95CE:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a95d4
FUN_080a95d4: @ 0x080A95D4
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x28]
	adds r2, r0, #1
	strh r2, [r4, #0x28]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A95F4
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #0
	strh r0, [r4, #0x2a]
	b _080A9624
_080A95F4:
	ldr r1, [r4, #0x34]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r2, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r2, r1
	strh r0, [r4, #0x1a]
	ldrh r1, [r4, #0x28]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080A9624
	adds r0, r2, #1
	strh r0, [r4, #0x2e]
_080A9624:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a962c
FUN_080a962c: @ 0x080A962C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov ip, r0
	movs r6, #0
	ldr r0, _080A96A8 @ =0x030046B8
	mov sl, r0
	ldr r1, _080A96AC @ =0x000003FF
	mov sb, r1
	ldr r2, _080A96B0 @ =0x085B0A08
	mov r8, r2
	movs r5, #0
	mov r4, ip
	adds r4, #0xa4
_080A964C:
	movs r0, #0x10
	strh r0, [r4]
	movs r0, #0x20
	strh r0, [r4, #2]
	mov r7, sl
	ldr r1, [r7]
	adds r1, #1
	mov r0, sb
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _080A96B4 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	lsls r3, r6, #5
	asrs r2, r2, #3
	movs r0, #0xf
	ands r2, r0
	adds r3, r3, r2
	adds r2, r3, #0
	subs r2, #8
	adds r1, #1
	mov r7, sb
	ands r1, r7
	mov r0, sl
	str r1, [r0]
	lsls r1, r1, #1
	ldr r7, _080A96B4 @ =0x0203B400
	adds r1, r1, r7
	ldrh r0, [r1]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r1, r0, #4
	adds r3, #0x38
	movs r0, #0xff
	ands r3, r0
	lsls r3, r3, #1
	add r3, r8
	movs r7, #0
	ldrsh r0, [r3, r7]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A96B8
	asrs r0, r0, #0xc
	b _080A96BE
	.align 2, 0
_080A96A8: .4byte 0x030046B8
_080A96AC: .4byte 0x000003FF
_080A96B0: .4byte 0x085B0A08
_080A96B4: .4byte 0x0203B400
_080A96B8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080A96BE:
	strh r0, [r4, #0x14]
	movs r0, #0xff
	ands r2, r0
	lsls r0, r2, #1
	add r0, r8
	movs r2, #0
	ldrsh r0, [r0, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080A96D6
	asrs r0, r0, #0xc
	b _080A96DC
_080A96D6:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080A96DC:
	strh r0, [r4, #0x16]
	mov r2, ip
	adds r2, #0x8c
	adds r2, r2, r5
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r0, #1
	strh r0, [r4, #0x12]
	movs r7, #0
	strh r7, [r4, #0x10]
	mov r0, ip
	adds r0, #0xc4
	adds r0, r0, r5
	ldr r1, _080A9718 @ =FUN_080a95d4
	str r1, [r0]
	adds r5, #0x3c
	adds r4, #0x3c
	adds r6, #1
	cmp r6, #7
	ble _080A964C
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9718: .4byte FUN_080a95d4

	thumb_func_start FUN_080a971c
FUN_080a971c: @ 0x080A971C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x28]
	adds r2, r0, #1
	strh r2, [r4, #0x28]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A973C
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #0
	strh r0, [r4, #0x2a]
	b _080A9756
_080A973C:
	ldr r1, [r4, #0x34]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrh r0, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r0, r1
	strh r0, [r4, #0x1a]
_080A9756:
	pop {r4}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a975c
FUN_080a975c: @ 0x080A975C
	push {r4, r5, r6, lr}
	mov r6, sb
	mov r5, r8
	push {r5, r6}
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r1, [r4, #0x34]
	adds r0, r4, #0
	movs r2, #6
	bl FUN_0822dafc
	ldr r0, _080A97F8 @ =0x0203B400
	mov sb, r0
	ldr r5, _080A97FC @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r1, _080A9800 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x10
	bl Mod
	adds r0, #8
	movs r6, #0
	strh r0, [r4, #0x18]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x10
	bl Mod
	adds r0, #0x18
	strh r0, [r4, #0x1a]
	strh r6, [r4, #0x1c]
	strh r6, [r4, #0x2c]
	ldr r0, [r5]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r5]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #2
	bl Mod
	adds r0, #2
	rsbs r0, r0, #0
	strh r0, [r4, #0x2e]
	strh r6, [r4, #0x30]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r6, [r4, #0x28]
	ldr r0, _080A9804 @ =FUN_080a971c
	str r0, [r4, #0x38]
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A97F8: .4byte 0x0203B400
_080A97FC: .4byte 0x030046B8
_080A9800: .4byte 0x000003FF
_080A9804: .4byte FUN_080a971c

	thumb_func_start FUN_080a9808
FUN_080a9808: @ 0x080A9808
	push {lr}
	adds r3, r0, #0
	ldrh r0, [r3, #0x28]
	adds r2, r0, #1
	strh r2, [r3, #0x28]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080A9828
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
	str r0, [r3]
	movs r0, #0
	strh r0, [r3, #0x2a]
	b _080A983A
_080A9828:
	ldr r1, [r3, #0x34]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r3, #0
	bl FUN_0822dafc
_080A983A:
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080a9840
FUN_080a9840: @ 0x080A9840
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	adds r4, r0, #0
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r1, [r4, #0x34]
	adds r0, r4, #0
	movs r2, #2
	bl FUN_0822dafc
	ldr r0, _080A98B0 @ =0x0203B400
	mov r8, r0
	ldr r5, _080A98B4 @ =0x030046B8
	ldr r0, [r5]
	adds r0, #1
	ldr r6, _080A98B8 @ =0x000003FF
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #0x50
	bl Mod
	adds r0, #0x18
	movs r2, #0
	strh r0, [r4, #0x18]
	ldr r0, [r5]
	adds r0, #1
	ands r0, r6
	str r0, [r5]
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #7
	ands r0, r1
	adds r0, #8
	strh r0, [r4, #0x1a]
	strh r2, [r4, #0x1c]
	movs r0, #1
	strh r0, [r4, #0x2a]
	strh r2, [r4, #0x28]
	ldr r0, _080A98BC @ =FUN_080a9808
	str r0, [r4, #0x38]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A98B0: .4byte 0x0203B400
_080A98B4: .4byte 0x030046B8
_080A98B8: .4byte 0x000003FF
_080A98BC: .4byte FUN_080a9808

	thumb_func_start FUN_080a98c0
FUN_080a98c0: @ 0x080A98C0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x8c
	movs r7, #0
	movs r6, #7
_080A98CC:
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	beq _080A98E0
	adds r0, r5, #0
	adds r0, #0xc4
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080A98E0:
	adds r4, #0x3c
	adds r7, #0x3c
	subs r6, #1
	cmp r6, #0
	bge _080A98CC
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a98f0
FUN_080a98f0: @ 0x080A98F0
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0x1e
	bne _080A9914
	adds r0, r5, #0
	bl FUN_080a962c
	ldr r0, _080A9948 @ =0x00000285
	bl PlaySound_082406e0
	ldr r0, [r5, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r5, #0x24]
_080A9914:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x3b
	bls _080A9942
	bl FUN_0824082c
	ldr r2, _080A994C @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	ldr r2, _080A9950 @ =0x030047A4
	ldr r0, [r2]
	adds r1, #3
	ands r0, r1
	str r0, [r2]
	adds r0, r5, #0
	bl KillEntity
_080A9942:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080A9948: .4byte 0x00000285
_080A994C: .4byte 0x030044BC
_080A9950: .4byte 0x030047A4

	thumb_func_start FUN_080a9954
FUN_080a9954: @ 0x080A9954
	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r1, r7, r0
	ldrh r2, [r1]
	cmp r2, #0
	bne _080A997A
	ldr r0, [r7, #0x18]
	movs r3, #0xd9
	lsls r3, r3, #2
	adds r0, r0, r3
	strh r2, [r0]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_080A997A:
	movs r0, #0
	mov sb, r0
	ldr r0, [r7, #0x18]
	ldr r4, _080A9AA8 @ =0x00000366
	adds r0, r0, r4
	ldrh r0, [r0]
	movs r1, #0x96
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bne _080A9994
	movs r2, #1
_080A9994:
	ldr r0, [r7, #0x18]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r3, _080A9AAC @ =0x0000FFFF
	mov r8, r3
	ldr r3, [r7, #0x18]
	adds r0, r3, r4
	ldrh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r2
	blo _080A99C6
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	ldr r0, _080A9AB0 @ =0x00000259
	bl sound_08240740
	movs r3, #1
	mov sb, r3
_080A99C6:
	ldr r6, _080A9AB4 @ =0x0203B400
	ldr r4, _080A9AB8 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r5, _080A9ABC @ =0x000003FF
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #3
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7c
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #1
	strh r1, [r7, #0x3c]
	ldr r0, [r4]
	adds r0, #1
	ands r0, r5
	str r0, [r4]
	lsls r0, r0, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	asrs r0, r0, #3
	movs r1, #3
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7e
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, #1
	strh r1, [r7, #0x3e]
	movs r1, #0x9b
	lsls r1, r1, #2
	adds r0, r7, r1
	ldrh r0, [r0]
	movs r5, #7
	ands r5, r0
	cmp r5, #0
	bne _080A9A44
	ldr r3, _080A9AC0 @ =0x0000026E
	adds r4, r7, r3
	ldrh r1, [r4]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x8c
	adds r0, r7, r0
	bl FUN_080a975c
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	mov r1, r8
	ands r0, r1
	cmp r0, #7
	bls _080A9A44
	strh r5, [r4]
_080A9A44:
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r0, r7, r3
	ldrh r0, [r0]
	movs r5, #0xf
	ands r5, r0
	cmp r5, #0
	bne _080A9A78
	ldr r0, _080A9AC0 @ =0x0000026E
	adds r4, r7, r0
	ldrh r1, [r4]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x8c
	adds r0, r7, r0
	bl FUN_080a9840
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080A9A78
	strh r5, [r4]
_080A9A78:
	movs r3, #0x9b
	lsls r3, r3, #2
	adds r1, r7, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	mov r0, sb
	cmp r0, #0
	beq _080A9A9C
	adds r3, #8
	adds r1, r7, r3
	ldr r0, _080A9AC4 @ =FUN_080a98f0
	str r0, [r1]
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
_080A9A9C:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9AA8: .4byte 0x00000366
_080A9AAC: .4byte 0x0000FFFF
_080A9AB0: .4byte 0x00000259
_080A9AB4: .4byte 0x0203B400
_080A9AB8: .4byte 0x030046B8
_080A9ABC: .4byte 0x000003FF
_080A9AC0: .4byte 0x0000026E
_080A9AC4: .4byte FUN_080a98f0

	thumb_func_start FUN_080a9ac8
FUN_080a9ac8: @ 0x080A9AC8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r7, r0, #0
	movs r0, #0x9c
	lsls r0, r0, #2
	adds r0, r0, r7
	mov sl, r0
	ldrh r0, [r0]
	adds r0, #1
	mov r1, sl
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080A9B44
	ldrh r0, [r1]
	movs r5, #8
	subs r5, r5, r0
	ldr r0, _080A9B70 @ =0x0203B400
	mov sb, r0
	ldr r4, _080A9B74 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080A9B78 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	adds r1, r5, #0
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7c
	ldrh r1, [r1]
	adds r1, r1, r0
	asrs r6, r5, #1
	subs r1, r1, r6
	strh r1, [r7, #0x3c]
	ldr r0, [r4]
	adds r0, #1
	mov r1, r8
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	adds r1, r5, #0
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7e
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, r1, r6
	strh r1, [r7, #0x3e]
_080A9B44:
	mov r1, sl
	ldrh r0, [r1]
	cmp r0, #0x1d
	bls _080A9B62
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, _080A9B7C @ =FUN_080a9954
	str r0, [r1]
	ldr r0, _080A9B80 @ =0x00000259
	bl PlaySound_082406e0
	movs r0, #0
	mov r1, sl
	strh r0, [r1]
_080A9B62:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9B70: .4byte 0x0203B400
_080A9B74: .4byte 0x030046B8
_080A9B78: .4byte 0x000003FF
_080A9B7C: .4byte FUN_080a9954
_080A9B80: .4byte 0x00000259

	thumb_func_start FUN_080a9b84
FUN_080a9b84: @ 0x080A9B84
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080A9BA8
	bl FUN_082407e0
	movs r2, #4
	ldr r1, _080A9BA4 @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	b _080A9BBC
	.align 2, 0
_080A9BA4: .4byte 0x030044BC
_080A9BA8:
	cmp r0, #1
	bne _080A9BBC
	movs r0, #0xe6
	bl PlaySound_082406e0
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
_080A9BBC:
	movs r2, #0x9c
	lsls r2, r2, #2
	adds r6, r5, r2
	ldrh r0, [r6]
	adds r0, #1
	adds r1, r0, #0
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080A9C00
	ldr r0, [r5, #0x24]
	movs r1, #3
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	adds r0, r5, #0
	bl FUN_080a962c
	movs r3, #0x9d
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, _080A9BFC @ =FUN_080a9ac8
	str r0, [r1]
	movs r0, #0
	strh r0, [r6]
	movs r0, #0xa1
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080A9C82
	.align 2, 0
_080A9BFC: .4byte FUN_080a9ac8
_080A9C00:
	adds r1, #0x22
	adds r0, r5, #0
	adds r0, #0x51
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	adds r0, #0x2c
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x84
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #0x10
	subs r2, r4, r2
	muls r1, r2, r1
	adds r0, r0, r1
	movs r1, #0x10
	bl Div
	strh r0, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x7e
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x86
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r4, r4, r2
	muls r1, r4, r1
	adds r0, r0, r1
	movs r1, #0x10
	bl Div
	adds r4, r0, #0
	ldrh r0, [r6]
	lsls r0, r0, #7
	movs r1, #0x14
	bl Div
	ldr r2, _080A9C74 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r0
	lsls r1, r1, #1
	adds r1, r1, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A9C78
	asrs r0, r0, #0xc
	b _080A9C7E
	.align 2, 0
_080A9C74: .4byte 0x085B0A08
_080A9C78:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080A9C7E:
	subs r0, r4, r0
	strh r0, [r5, #0x3e]
_080A9C82:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080a9c88
FUN_080a9c88: @ 0x080A9C88
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080a98c0
	movs r1, #0x9d
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080a9ca8
FUN_080a9ca8: @ 0x080A9CA8
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r0, #0x1c
	bl FUN_0822f1c0
	adds r4, #0x8c
	movs r5, #7
_080A9CB6:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080A9CB6
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start FUN_080a9ccc
FUN_080a9ccc: @ 0x080A9CCC
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r4, r0, #0
	ldr r0, _080A9D28 @ =0x0000CB05
	ldr r1, _080A9D2C @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	add r2, sp, #0x10
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5, r6}
	stm r2!, {r3, r5, r6}
	ldm r0!, {r3, r5}
	stm r2!, {r3, r5}
	add r0, sp, #0x10
	bl OpenSpriteSetFile
	adds r2, r4, #0
	adds r2, #0x7c
	movs r1, #0
	movs r0, #8
	strh r0, [r2]
	adds r3, r4, #0
	adds r3, #0x7e
	movs r0, #0x18
	strh r0, [r3]
	adds r0, r4, #0
	adds r0, #0x80
	strh r1, [r0]
	subs r0, #0x64
	str r1, [sp]
	str r1, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r2, [sp, #0xc]
	add r1, sp, #0x10
	movs r2, #0x98
	movs r3, #0x33
	bl FUN_0822f3fc
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A9D28: .4byte 0x0000CB05
_080A9D2C: .4byte 0x00005D04

	thumb_func_start FUN_080a9d30
FUN_080a9d30: @ 0x080A9D30
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	ldr r0, _080A9DA4 @ =0x00001C1E
	bl GetParticleGroup
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	mov r5, sl
	adds r5, #0x8c
	mov r8, r0
	movs r7, #7
_080A9D50:
	mov r4, sl
	adds r4, #0xc0
	add r4, r8
	str r6, [r4]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x11
	bl FUN_0822d9f0
	adds r0, r5, #0
	movs r1, #4
	rsbs r1, r1, #0
	adds r2, r1, #0
	bl FUN_0822dad4
	ldr r1, [r4]
	adds r0, r5, #0
	movs r2, #2
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	mov r0, sb
	strb r0, [r5, #0xf]
	mov r0, sb
	strh r0, [r5, #0x28]
	strh r0, [r5, #0x2a]
	adds r5, #0x3c
	movs r0, #0x3c
	add r8, r0
	subs r7, #1
	cmp r7, #0
	bge _080A9D50
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080A9DA4: .4byte 0x00001C1E

	thumb_func_start FUN_080a9da8
FUN_080a9da8: @ 0x080A9DA8
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r7, r0, #0
	str r1, [r7, #0x18]
	ldr r0, [r1, #0x2c]
	ldr r1, [r1, #0x30]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _080A9DEC @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r6, r7, #0
	adds r6, #0x84
	mov r5, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A9DF0
	asrs r0, r0, #8
	b _080A9DF6
	.align 2, 0
_080A9DEC: .4byte 0x0000FFFF
_080A9DF0:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A9DF6:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080A9E08
	asrs r0, r0, #8
	b _080A9E0E
_080A9E08:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A9E0E:
	adds r4, r0, #0
	movs r0, #2
	ldrsh r1, [r5, r0]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080A9E22
	asrs r0, r0, #8
	b _080A9E28
_080A9E22:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080A9E28:
	subs r2, r4, r0
	movs r5, #0
	adds r4, r4, r0
	ldr r3, _080A9E7C @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	adds r0, r7, #0
	bl FUN_080a9ccc
	adds r0, r7, #0
	bl FUN_080a9d30
	movs r0, #0x9d
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, _080A9E80 @ =FUN_080a9b84
	str r0, [r1]
	movs r1, #0x9c
	lsls r1, r1, #2
	adds r0, r7, r1
	strh r5, [r0]
	ldr r2, _080A9E84 @ =0x030047A4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080A9E7C: .4byte 0x030047C8
_080A9E80: .4byte FUN_080a9b84
_080A9E84: .4byte 0x030047A4

	thumb_func_start FUN_080a9e88
FUN_080a9e88: @ 0x080A9E88
	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080A9EC4
	ldr r1, _080A9EBC @ =FUN_080a9c88
	ldr r2, _080A9EC0 @ =0x080A9CA9
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_080a9da8
	cmp r0, #0
	bge _080A9EC4
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080A9EC6
	.align 2, 0
_080A9EBC: .4byte FUN_080a9c88
_080A9EC0: .4byte 0x080A9CA9
_080A9EC4:
	adds r0, r4, #0
_080A9EC6:
	pop {r4, r5}
	pop {r1}
	bx r1

	thumb_func_start Entity87FE_Update
Entity87FE_Update: @ 0x080A9ECC
	push {r4, lr}
	adds r4, r0, #0
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	bne _080A9F02
	ldr r0, [r4, #0x18]
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrh r1, [r4, #0x20]
	ldrh r2, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r3, [r4, #0x18]
	ldr r2, _080A9F60 @ =0x00000366
	adds r0, r3, r2
	ldrh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r2
	blo _080A9F02
	movs r1, #0xd9
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	movs r0, #1
	strb r0, [r4, #0x1c]
_080A9F02:
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080A9F34
	ldr r0, [r4, #0x18]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r0, r0, r2
	ldrh r1, [r4, #0x22]
	ldrh r2, [r0]
	adds r1, r1, r2
	strh r1, [r0]
	ldr r3, [r4, #0x18]
	ldr r2, _080A9F64 @ =0x0000036A
	adds r0, r3, r2
	ldrh r2, [r0]
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	cmp r1, r2
	blo _080A9F34
	movs r1, #0xda
	lsls r1, r1, #2
	adds r0, r3, r1
	strh r2, [r0]
	movs r0, #1
	strb r0, [r4, #0x1d]
_080A9F34:
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	beq _080A9F58
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	beq _080A9F58
	ldr r0, _080A9F68 @ =0x00000259
	bl sound_08240740
	ldr r0, [r4, #0x24]
	cmp r0, #0
	beq _080A9F52
	movs r1, #0
	bl Script_ExecById
_080A9F52:
	adds r0, r4, #0
	bl KillEntity
_080A9F58:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080A9F60: .4byte 0x00000366
_080A9F64: .4byte 0x0000036A
_080A9F68: .4byte 0x00000259

	thumb_func_start Entity87FE_Destroy
Entity87FE_Destroy: @ 0x080A9F6C
	movs r0, #0
	bx lr

	thumb_func_start Entity87FE_Init
Entity87FE_Init: @ 0x080A9F70
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r0, _080A9F84 @ =0x03002BE0
	ldr r0, [r0]
	str r0, [r4, #0x18]
	cmp r0, #0
	bne _080A9F88
	movs r0, #1
	rsbs r0, r0, #0
	b _080AA044
	.align 2, 0
_080A9F84: .4byte 0x03002BE0
_080A9F88:
	movs r0, #0x6c
	bl prepare_08231510
	cmp r0, #0
	beq _080A9F9A
	bl Script_GetValue
	adds r5, r0, #0
	b _080A9F9C
_080A9F9A:
	movs r5, #0
_080A9F9C:
	movs r0, #0x65
	bl prepare_08231510
	cmp r0, #0
	beq _080A9FAE
	bl Script_GetValue
	adds r6, r0, #0
	b _080A9FB0
_080A9FAE:
	movs r6, #0
_080A9FB0:
	cmp r5, #0
	beq _080A9FE4
	ldr r0, [r4, #0x18]
	movs r2, #0xd9
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r3, _080A9FE0 @ =0x00000366
	adds r2, r0, r3
	ldrh r0, [r1]
	ldrh r1, [r2]
	cmp r0, r1
	bhs _080A9FE4
	ldrh r0, [r2]
	movs r1, #0x5a
	bl Div
	strh r0, [r4, #0x20]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080A9FDC
	movs r0, #1
	strh r0, [r4, #0x20]
_080A9FDC:
	movs r0, #0
	b _080A9FE6
	.align 2, 0
_080A9FE0: .4byte 0x00000366
_080A9FE4:
	movs r0, #1
_080A9FE6:
	strb r0, [r4, #0x1c]
	cmp r6, #0
	beq _080AA01C
	ldr r0, [r4, #0x18]
	movs r2, #0xda
	lsls r2, r2, #2
	adds r1, r0, r2
	ldr r3, _080AA018 @ =0x0000036A
	adds r2, r0, r3
	ldrh r0, [r1]
	ldrh r1, [r2]
	cmp r0, r1
	bhs _080AA01C
	ldrh r0, [r2]
	movs r1, #0x5a
	bl Div
	strh r0, [r4, #0x22]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _080AA014
	movs r0, #1
	strh r0, [r4, #0x22]
_080AA014:
	movs r0, #0
	b _080AA01E
	.align 2, 0
_080AA018: .4byte 0x0000036A
_080AA01C:
	movs r0, #1
_080AA01E:
	strb r0, [r4, #0x1d]
	ldrb r0, [r4, #0x1c]
	cmp r0, #0
	beq _080AA02C
	ldrb r0, [r4, #0x1d]
	cmp r0, #0
	bne _080AA032
_080AA02C:
	ldr r0, _080AA04C @ =0x00000259
	bl PlaySound_082406e0
_080AA032:
	movs r0, #0x70
	bl prepare_08231510
	cmp r0, #0
	beq _080AA040
	bl Script_GetValue
_080AA040:
	str r0, [r4, #0x24]
	movs r0, #0
_080AA044:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_080AA04C: .4byte 0x00000259

	thumb_func_start Entity87FE_Create
Entity87FE_Create: @ 0x080AA050
	push {r4, lr}
	movs r0, #9
	movs r1, #0x28
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AA084
	ldr r1, _080AA07C @ =Entity87FE_Update
	ldr r2, _080AA080 @ =Entity87FE_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl Entity87FE_Init
	cmp r0, #0
	bge _080AA084
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AA086
	.align 2, 0
_080AA07C: .4byte Entity87FE_Update
_080AA080: .4byte Entity87FE_Destroy
_080AA084:
	adds r0, r4, #0
_080AA086:
	pop {r4}
	pop {r1}
	bx r1

	thumb_func_start FUN_080aa08c
FUN_080aa08c: @ 0x080AA08C
	push {r4, lr}
	adds r4, r0, #0
	ldrh r0, [r4, #0x28]
	adds r2, r0, #1
	strh r2, [r4, #0x28]
	lsls r0, r2, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AA0AC
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	movs r0, #0
	strh r0, [r4, #0x2a]
	b _080AA0DC
_080AA0AC:
	ldr r1, [r4, #0x34]
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x12
	movs r0, #1
	ands r2, r0
	adds r2, #2
	adds r0, r4, #0
	bl FUN_0822dafc
	ldrh r0, [r4, #0x2c]
	ldrh r1, [r4, #0x18]
	adds r0, r0, r1
	strh r0, [r4, #0x18]
	ldrh r2, [r4, #0x2e]
	ldrh r1, [r4, #0x1a]
	adds r0, r2, r1
	strh r0, [r4, #0x1a]
	ldrh r1, [r4, #0x28]
	movs r0, #7
	ands r0, r1
	cmp r0, #0
	bne _080AA0DC
	adds r0, r2, #1
	strh r0, [r4, #0x2e]
_080AA0DC:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080aa0e4
FUN_080aa0e4: @ 0x080AA0E4
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	movs r7, #0
	ldr r0, _080AA174 @ =0x000003FF
	mov sl, r0
	ldr r1, _080AA178 @ =0x085B0A08
	mov sb, r1
	mov ip, r5
	movs r6, #0
	movs r2, #0xff
	mov r8, r2
_080AA102:
	adds r0, r5, #0
	adds r0, #0x7c
	ldrh r0, [r0]
	adds r0, #8
	movs r1, #0xbe
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x7e
	ldrh r0, [r0]
	adds r0, #8
	movs r1, #0xbf
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	ldr r0, _080AA17C @ =0x030046B8
	ldr r1, [r0]
	adds r1, #1
	mov r2, sl
	ands r1, r2
	lsls r0, r1, #1
	ldr r2, _080AA180 @ =0x0203B400
	adds r0, r0, r2
	ldrh r2, [r0]
	lsls r3, r7, #5
	asrs r2, r2, #3
	movs r0, #0xf
	ands r2, r0
	adds r3, r3, r2
	adds r2, r3, #0
	subs r2, #8
	adds r1, #1
	mov r0, sl
	ands r1, r0
	ldr r0, _080AA17C @ =0x030046B8
	str r1, [r0]
	lsls r1, r1, #1
	ldr r0, _080AA180 @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	asrs r0, r0, #3
	movs r1, #3
	ands r0, r1
	adds r4, r0, #4
	adds r3, #0x38
	mov r1, r8
	ands r3, r1
	lsls r3, r3, #1
	add r3, sb
	movs r1, #0
	ldrsh r0, [r3, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AA184
	asrs r1, r0, #0xc
	b _080AA18A
	.align 2, 0
_080AA174: .4byte 0x000003FF
_080AA178: .4byte 0x085B0A08
_080AA17C: .4byte 0x030046B8
_080AA180: .4byte 0x0203B400
_080AA184:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080AA18A:
	movs r0, #0xc8
	lsls r0, r0, #1
	add r0, ip
	strh r1, [r0]
	mov r0, r8
	ands r2, r0
	lsls r0, r2, #1
	add r0, sb
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AA1A8
	asrs r0, r0, #0xc
	b _080AA1AE
_080AA1A8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AA1AE:
	movs r1, #0xc9
	lsls r1, r1, #1
	add r1, ip
	strh r0, [r1]
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r2, r5, r0
	adds r2, r2, r6
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	movs r1, #0xc7
	lsls r1, r1, #1
	add r1, ip
	movs r0, #1
	strh r0, [r1]
	movs r0, #0xc6
	lsls r0, r0, #1
	add r0, ip
	movs r1, #0
	strh r1, [r0]
	movs r2, #0xce
	lsls r2, r2, #1
	adds r0, r5, r2
	adds r0, r0, r6
	ldr r1, _080AA204 @ =FUN_080aa08c
	str r1, [r0]
	movs r2, #0x3c
	add ip, r2
	adds r6, #0x3c
	adds r7, #1
	cmp r7, #7
	ble _080AA102
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AA204: .4byte FUN_080aa08c

	thumb_func_start FUN_080aa208
FUN_080aa208: @ 0x080AA208
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r7, #0
	movs r5, #7
_080AA216:
	ldrh r0, [r4, #0x2a]
	cmp r0, #0
	beq _080AA22C
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r6, r1
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_080AA22C:
	adds r4, #0x3c
	adds r7, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080AA216
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aa23c
FUN_080aa23c: @ 0x080AA23C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _080AA260 @ =0x0000034A
	adds r4, r5, r0
	ldrh r1, [r4]
	movs r0, #0x10
	subs r0, r0, r1
	lsls r0, r0, #1
	bl FUN_0823b9cc
	ldrh r0, [r4]
	cmp r0, #5
	bhi _080AA264
	adds r0, r5, #0
	adds r0, #0x94
	bl FUN_08236400
	b _080AA274
	.align 2, 0
_080AA260: .4byte 0x0000034A
_080AA264:
	cmp r0, #6
	bne _080AA274
	ldr r0, _080AA294 @ =0x030047A4
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_080AA274:
	ldr r0, _080AA298 @ =0x0000034A
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bls _080AA28C
	adds r0, r5, #0
	bl KillEntity
_080AA28C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_080AA294: .4byte 0x030047A4
_080AA298: .4byte 0x0000034A

	thumb_func_start FUN_080aa29c
FUN_080aa29c: @ 0x080AA29C
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov r8, r0
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r0]
	movs r0, #0x2c
	muls r0, r1, r0
	adds r0, #0xe4
	mov r1, r8
	adds r7, r1, r0
	ldr r0, _080AA30C @ =0x0000034A
	add r0, r8
	ldrh r0, [r0]
	movs r1, #0x12
	bl Div
	ldr r6, _080AA310 @ =0x0203B400
	ldr r5, _080AA314 @ =0x030046B8
	ldr r2, [r5]
	adds r2, #1
	ldr r4, _080AA318 @ =0x000003FF
	ands r2, r4
	lsls r1, r2, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	lsls r0, r0, #6
	movs r3, #0x3f
	ands r1, r3
	adds r3, r0, r1
	movs r1, #0xff
	ands r3, r1
	adds r2, #1
	ands r2, r4
	str r2, [r5]
	lsls r2, r2, #1
	adds r2, r2, r6
	ldrh r0, [r2]
	ands r0, r1
	adds r4, r0, #0
	adds r4, #0x80
	ldr r2, _080AA31C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r4, r0
	cmp r0, #0
	blt _080AA320
	asrs r0, r0, #0xc
	b _080AA326
	.align 2, 0
_080AA30C: .4byte 0x0000034A
_080AA310: .4byte 0x0203B400
_080AA314: .4byte 0x030046B8
_080AA318: .4byte 0x000003FF
_080AA31C: .4byte 0x085B0A08
_080AA320:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AA326:
	adds r5, r0, #0
	ldr r1, _080AA344 @ =0x085B0A08
	lsls r0, r3, #1
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	adds r1, r4, #0
	muls r1, r0, r1
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _080AA348
	asrs r2, r0, #0xd
	b _080AA34E
	.align 2, 0
_080AA344: .4byte 0x085B0A08
_080AA348:
	rsbs r0, r0, #0
	asrs r0, r0, #0xd
	rsbs r2, r0, #0
_080AA34E:
	ldr r0, [r7]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r7]
	ldr r0, _080AA3D4 @ =0x03003540
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r7, #0x1c]
	str r1, [r7, #0x20]
	ldrh r0, [r7, #0x1c]
	subs r0, #0x4b
	subs r1, r5, r2
	adds r0, r0, r1
	movs r3, #0
	strh r0, [r7, #0x1c]
	ldr r1, _080AA3D8 @ =0x00000352
	adds r0, r1, #0
	ldrh r1, [r7, #0x1e]
	adds r0, r0, r1
	strh r0, [r7, #0x1e]
	ldrh r0, [r7, #0x20]
	subs r0, #0x4b
	adds r1, r5, r2
	adds r0, r0, r1
	strh r0, [r7, #0x20]
	movs r2, #0xac
	lsls r2, r2, #1
	add r2, r8
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r2]
	adds r0, r0, r1
	movs r1, #1
	strb r1, [r0]
	ldrh r1, [r2]
	lsls r1, r1, #1
	movs r0, #0xb0
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	strh r3, [r0]
	adds r1, r7, #0
	adds r1, #0x1c
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	adds r5, r1, #0
	cmp r3, #0
	blt _080AA3CE
	cmp r2, #0
	blt _080AA3CE
	ldr r0, _080AA3DC @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080AA3CE
	ldr r0, _080AA3E0 @ =0x030046AC
	ldr r0, [r0]
	cmp r2, r0
	blo _080AA3E4
_080AA3CE:
	movs r4, #0
	b _080AA3F2
	.align 2, 0
_080AA3D4: .4byte 0x03003540
_080AA3D8: .4byte 0x00000352
_080AA3DC: .4byte 0x030046A8
_080AA3E0: .4byte 0x030046AC
_080AA3E4:
	ldr r0, _080AA404 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r2, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_080AA3F2:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080AA408
	adds r0, #4
	b _080AA414
	.align 2, 0
_080AA404: .4byte 0x030046A4
_080AA408:
	ldr r0, _080AA438 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080AA414:
	ldrh r0, [r0, #2]
	movs r1, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080AA43C
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	ldrh r0, [r0]
	lsls r0, r0, #1
	movs r1, #0xae
	lsls r1, r1, #1
	add r1, r8
	adds r1, r1, r0
	movs r0, #0
	strh r0, [r1]
	b _080AA4D0
	.align 2, 0
_080AA438: .4byte 0x030046A4
_080AA43C:
	ldrh r0, [r7, #0x1c]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	ldrh r0, [r5, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _080AA460
	cmp r1, #0
	blt _080AA460
	ldr r0, _080AA464 @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _080AA460
	ldr r0, _080AA468 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080AA46C
_080AA460:
	movs r4, #0
	b _080AA47A
	.align 2, 0
_080AA464: .4byte 0x030046A8
_080AA468: .4byte 0x030046AC
_080AA46C:
	ldr r0, _080AA48C @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r2
_080AA47A:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080AA490
	adds r0, #4
	b _080AA49C
	.align 2, 0
_080AA48C: .4byte 0x030046A4
_080AA490:
	ldr r0, _080AA4B0 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080AA49C:
	ldrb r1, [r0]
	lsrs r3, r1, #4
	movs r0, #0xf
	ands r0, r1
	lsls r2, r0, #8
	cmp r3, #1
	beq _080AA4B4
	cmp r3, #2
	beq _080AA4B8
	b _080AA4BC
	.align 2, 0
_080AA4B0: .4byte 0x030046A4
_080AA4B4:
	ldrb r0, [r5, #4]
	b _080AA4BA
_080AA4B8:
	ldrb r0, [r5]
_080AA4BA:
	subs r2, r2, r0
_080AA4BC:
	movs r0, #0xac
	lsls r0, r0, #1
	add r0, r8
	ldrh r1, [r0]
	lsls r1, r1, #1
	movs r0, #0xae
	lsls r0, r0, #1
	add r0, r8
	adds r0, r0, r1
	strh r2, [r0]
_080AA4D0:
	movs r2, #0xac
	lsls r2, r2, #1
	add r2, r8
	ldrh r1, [r2]
	movs r0, #1
	subs r0, r0, r1
	strh r0, [r2]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aa4e8
FUN_080aa4e8: @ 0x080AA4E8
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov r8, r0
	movs r0, #0
	mov sb, r0
	movs r1, #0xb0
	lsls r1, r1, #1
	add r1, r8
	str r1, [sp]
	mov sl, r0
	movs r7, #0xb0
	lsls r7, r7, #1
	add r7, r8
_080AA50A:
	movs r0, #0xad
	lsls r0, r0, #1
	add r0, r8
	mov r1, sb
	adds r6, r0, r1
	ldrb r2, [r6]
	cmp r2, #0
	beq _080AA5B0
	movs r0, #0x2c
	mov r1, sb
	muls r1, r0, r1
	adds r0, r1, #0
	adds r0, #0xe4
	mov r1, r8
	adds r5, r1, r0
	cmp r2, #1
	bne _080AA584
	ldrh r0, [r5, #0x1e]
	subs r0, #0x32
	movs r1, #0
	mov ip, r1
	movs r3, #0
	strh r0, [r5, #0x1e]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	movs r4, #0xae
	lsls r4, r4, #1
	add r4, r8
	add r4, sl
	ldrh r1, [r4]
	cmp r0, r1
	bgt _080AA564
	ldr r0, _080AA560 @ =0x000001FF
	str r3, [sp, #4]
	bl PlaySound_082406e0
	ldrh r0, [r4]
	strh r0, [r5, #0x1e]
	movs r0, #2
	strb r0, [r6]
	ldr r3, [sp, #4]
	b _080AA5AE
	.align 2, 0
_080AA560: .4byte 0x000001FF
_080AA564:
	ldr r1, [sp]
	add r1, sl
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x18
	bls _080AA5B0
	ldr r0, [r5]
	orrs r0, r2
	str r0, [r5]
	mov r0, ip
	strb r0, [r6]
	strh r3, [r1]
	b _080AA5B0
_080AA584:
	ldrh r0, [r7]
	adds r1, r0, #1
	movs r2, #0
	movs r3, #0
	strh r1, [r7]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _080AA5A4
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x12
	subs r1, #0xc
	ldrh r0, [r5, #0x1e]
	subs r0, r0, r1
	strh r0, [r5, #0x1e]
	b _080AA5B0
_080AA5A4:
	ldr r0, [r5]
	movs r1, #1
	orrs r0, r1
	str r0, [r5]
	strb r2, [r6]
_080AA5AE:
	strh r3, [r7]
_080AA5B0:
	movs r1, #2
	add sl, r1
	adds r7, #2
	movs r0, #1
	add sb, r0
	mov r1, sb
	cmp r1, #1
	ble _080AA50A
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aa5d0
FUN_080aa5d0: @ 0x080AA5D0
	push {r4, r5, r6, lr}
	adds r4, r0, #0
	ldr r1, _080AA64C @ =0x0000034A
	adds r0, r4, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080AA5F2
	cmp r0, #0x12
	beq _080AA5F2
	cmp r0, #0x24
	beq _080AA5F2
	cmp r0, #0x36
	beq _080AA5F2
	cmp r0, #0x48
	beq _080AA5F2
	cmp r0, #0x5a
	bne _080AA5F8
_080AA5F2:
	adds r0, r4, #0
	bl FUN_080aa29c
_080AA5F8:
	adds r0, r4, #0
	bl FUN_080aa4e8
	ldr r0, _080AA64C @ =0x0000034A
	adds r1, r4, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x79
	bls _080AA646
	ldr r5, _080AA650 @ =0x030044BC
	ldr r6, _080AA654 @ =FUN_080aa23c
	movs r3, #1
	adds r1, r4, #0
	adds r1, #0xe4
	movs r0, #0x88
	lsls r0, r0, #1
	adds r2, r4, r0
_080AA620:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x2c
	cmp r1, r2
	ble _080AA620
	movs r2, #0
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r5]
	ands r0, r1
	str r0, [r5]
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	str r6, [r0]
	subs r1, #2
	adds r0, r4, r1
	strh r2, [r0]
_080AA646:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AA64C: .4byte 0x0000034A
_080AA650: .4byte 0x030044BC
_080AA654: .4byte FUN_080aa23c

	thumb_func_start FUN_080aa658
FUN_080aa658: @ 0x080AA658
	push {r4, r5, lr}
	sub sp, #0xc
	adds r4, r0, #0
	ldr r0, _080AA6A4 @ =0x0000034A
	adds r5, r4, r0
	ldrh r0, [r5]
	cmp r0, #0
	bne _080AA692
	ldr r2, _080AA6A8 @ =0x030044BC
	movs r1, #5
	rsbs r1, r1, #0
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
	movs r0, #0x67
	bl PlaySound_082406e0
	movs r0, #0x1f
	str r0, [sp]
	ldr r0, _080AA6AC @ =0x00001FFF
	str r0, [sp, #4]
	movs r0, #1
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #4
	movs r2, #0x1f
	movs r3, #0x1f
	bl FUN_0823ce68
_080AA692:
	ldrh r0, [r5]
	cmp r0, #5
	bhi _080AA6B0
	adds r0, r4, #0
	adds r0, #0x94
	bl FUN_08236400
	b _080AA6C0
	.align 2, 0
_080AA6A4: .4byte 0x0000034A
_080AA6A8: .4byte 0x030044BC
_080AA6AC: .4byte 0x00001FFF
_080AA6B0:
	cmp r0, #6
	bne _080AA6C0
	ldr r0, _080AA6DC @ =0x030047A4
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
_080AA6C0:
	ldr r0, _080AA6E0 @ =0x0000034A
	adds r2, r4, r0
	ldrh r0, [r2]
	adds r1, r0, #1
	strh r1, [r2]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x2f
	bls _080AA6E4
	adds r0, r4, #0
	bl KillEntity
	b _080AA6FE
	.align 2, 0
_080AA6DC: .4byte 0x030047A4
_080AA6E0: .4byte 0x0000034A
_080AA6E4:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080AA6F4
	movs r0, #0x20
	bl FUN_0823b9cc
	b _080AA6FE
_080AA6F4:
	ldrh r1, [r2]
	movs r0, #0x30
	subs r0, r0, r1
	bl FUN_0823b9cc
_080AA6FE:
	add sp, #0xc
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_080aa708
FUN_080aa708: @ 0x080AA708
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	ldr r0, _080AA7EC @ =0x0000034A
	adds r0, r0, r7
	mov sl, r0
	ldrh r0, [r0]
	adds r0, #1
	mov r1, sl
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bhi _080AA784
	ldrh r0, [r1]
	movs r5, #8
	subs r5, r5, r0
	ldr r2, _080AA7F0 @ =0x0203B400
	mov sb, r2
	ldr r4, _080AA7F4 @ =0x030046B8
	ldr r0, [r4]
	adds r0, #1
	ldr r1, _080AA7F8 @ =0x000003FF
	mov r8, r1
	ands r0, r1
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	adds r1, r5, #0
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7c
	ldrh r1, [r1]
	adds r1, r1, r0
	asrs r6, r5, #1
	subs r1, r1, r6
	strh r1, [r7, #0x3c]
	ldr r0, [r4]
	adds r0, #1
	mov r2, r8
	ands r0, r2
	str r0, [r4]
	lsls r0, r0, #1
	add r0, sb
	ldrh r0, [r0]
	asrs r0, r0, #3
	adds r1, r5, #0
	bl Mod
	adds r1, r7, #0
	adds r1, #0x7e
	ldrh r1, [r1]
	adds r1, r1, r0
	subs r1, r1, r6
	strh r1, [r7, #0x3e]
_080AA784:
	mov r1, sl
	ldrh r0, [r1]
	cmp r0, #0x1e
	bne _080AA7A0
	adds r0, r7, #0
	bl FUN_080aa0e4
	ldr r0, _080AA7FC @ =0x00000285
	bl PlaySound_082406e0
	ldr r0, [r7, #0x24]
	movs r1, #1
	orrs r0, r1
	str r0, [r7, #0x24]
_080AA7A0:
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r1, [r0]
	cmp r1, #1
	bne _080AA7CA
	mov r2, sl
	ldrh r0, [r2]
	cmp r0, #0x1d
	bne _080AA7CA
	movs r0, #4
	str r0, [sp]
	ldr r0, _080AA800 @ =0x00001FFF
	str r0, [sp, #4]
	str r1, [sp, #8]
	movs r0, #3
	movs r1, #5
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
_080AA7CA:
	ldr r1, _080AA7EC @ =0x0000034A
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0x2c
	bls _080AA81A
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AA808
	movs r0, #0xd3
	lsls r0, r0, #2
	adds r1, r7, r0
	ldr r0, _080AA804 @ =FUN_080aa5d0
	b _080AA810
	.align 2, 0
_080AA7EC: .4byte 0x0000034A
_080AA7F0: .4byte 0x0203B400
_080AA7F4: .4byte 0x030046B8
_080AA7F8: .4byte 0x000003FF
_080AA7FC: .4byte 0x00000285
_080AA800: .4byte 0x00001FFF
_080AA804: .4byte FUN_080aa5d0
_080AA808:
	movs r2, #0xd3
	lsls r2, r2, #2
	adds r1, r7, r2
	ldr r0, _080AA82C @ =FUN_080aa658
_080AA810:
	str r0, [r1]
	ldr r0, _080AA830 @ =0x0000034A
	adds r1, r7, r0
	movs r0, #0
	strh r0, [r1]
_080AA81A:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AA82C: .4byte FUN_080aa658
_080AA830: .4byte 0x0000034A

	thumb_func_start FUN_080aa834
FUN_080aa834: @ 0x080AA834
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, [r5, #0x24]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5, #0x24]
	ldr r0, _080AA874 @ =0x0000034A
	adds r6, r5, r0
	ldrh r0, [r6]
	adds r0, #1
	strh r0, [r6]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #7
	bls _080AA87C
	ldr r0, [r5, #0x24]
	subs r1, #1
	ands r0, r1
	str r0, [r5, #0x24]
	movs r3, #0xd3
	lsls r3, r3, #2
	adds r1, r5, r3
	ldr r0, _080AA878 @ =0x080AA709
	str r0, [r1]
	movs r0, #0
	strh r0, [r6]
	movs r0, #0xa1
	lsls r0, r0, #2
	bl PlaySound_082406e0
	b _080AA8D2
	.align 2, 0
_080AA874: .4byte 0x0000034A
_080AA878: .4byte 0x080AA709
_080AA87C:
	ldrh r0, [r6]
	lsls r0, r0, #1
	adds r0, #0x20
	adds r1, r5, #0
	adds r1, #0x51
	strb r0, [r1]
	subs r1, #1
	strb r0, [r1]
	adds r0, r5, #0
	adds r0, #0x7c
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x84
	movs r3, #0
	ldrsh r1, [r1, r3]
	movs r4, #8
	subs r2, r4, r2
	muls r1, r2, r1
	adds r0, r0, r1
	movs r1, #8
	bl Div
	strh r0, [r5, #0x3c]
	adds r0, r5, #0
	adds r0, #0x7e
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldrh r2, [r6]
	muls r0, r2, r0
	adds r1, r5, #0
	adds r1, #0x86
	movs r3, #0
	ldrsh r1, [r1, r3]
	subs r4, r4, r2
	muls r1, r4, r1
	adds r0, r0, r1
	movs r1, #8
	bl Div
	strh r0, [r5, #0x3e]
_080AA8D2:
	pop {r4, r5, r6}
	pop {r0}
	bx r0

	thumb_func_start FUN_080aa8d8
FUN_080aa8d8: @ 0x080AA8D8
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080aa208
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_080aa8f8
FUN_080aa8f8: @ 0x080AA8F8
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	adds r0, #0x1c
	bl FUN_0822f1c0
	movs r0, #0xb2
	lsls r0, r0, #1
	adds r4, r6, r0
	movs r5, #7
_080AA90A:
	adds r0, r4, #0
	bl FUN_0822dabc
	adds r4, #0x3c
	subs r5, #1
	cmp r5, #0
	bge _080AA90A
	movs r1, #0xd2
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AA938
	adds r4, r6, #0
	adds r4, #0xe4
	movs r5, #1
_080AA92A:
	adds r0, r4, #0
	bl FUN_0822a4e0
	adds r4, #0x2c
	subs r5, #1
	cmp r5, #0
	bge _080AA92A
_080AA938:
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1

	thumb_func_start FUN_080aa940
FUN_080aa940: @ 0x080AA940
	push {r4, r5, r6, lr}
	sub sp, #0x30
	adds r5, r0, #0
	ldr r0, _080AA9C8 @ =0x0000CB05
	ldr r1, _080AA9CC @ =0x00005D04
	bl GetFile
	adds r1, r0, #0
	add r2, sp, #0x10
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4, r6}
	stm r2!, {r3, r4, r6}
	ldm r0!, {r3, r4}
	stm r2!, {r3, r4}
	add r0, sp, #0x10
	bl OpenSpriteSetFile
	movs r6, #0xd2
	lsls r6, r6, #2
	adds r0, r5, r6
	ldrh r0, [r0]
	movs r2, #0x2c
	cmp r0, #0
	bne _080AA974
	movs r2, #0x27
_080AA974:
	adds r3, r5, #0
	adds r3, #0x84
	ldrh r0, [r3]
	subs r0, #8
	adds r1, r5, #0
	adds r1, #0x7c
	movs r4, #0
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x86
	ldrh r0, [r0]
	subs r0, #0x28
	adds r1, #2
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0x88
	ldrh r1, [r0]
	subs r0, #8
	strh r1, [r0]
	subs r0, #0x64
	adds r2, #0x68
	movs r1, #1
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #0x3c
	str r1, [sp, #8]
	str r3, [sp, #0xc]
	add r1, sp, #0x10
	movs r3, #0x32
	bl FUN_0822f3fc
	adds r0, r5, #0
	adds r0, #0x51
	movs r1, #0x22
	strb r1, [r0]
	subs r0, #1
	strb r1, [r0]
	add sp, #0x30
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080AA9C8: .4byte 0x0000CB05
_080AA9CC: .4byte 0x00005D04

	thumb_func_start FUN_080aa9d0
FUN_080aa9d0: @ 0x080AA9D0
	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, _080AAA24 @ =0x000024BA
	bl Video_GetActorSprite
	movs r6, #0
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r7, r5, r0
_080AA9E8:
	movs r0, #0x2c
	adds r4, r6, #0
	muls r4, r0, r4
	adds r0, r4, #0
	adds r0, #0xe4
	adds r0, r5, r0
	adds r1, r7, #0
	movs r2, #1
	bl FUN_0822a470
	adds r0, r7, #0
	ldr r1, _080AAA28 @ =0x0000027D
	bl FUN_0822b20c
	movs r1, #0x80
	lsls r1, r1, #1
	adds r2, r5, r1
	adds r2, r2, r4
	ldr r0, [r5, #0x18]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [r2]
	str r1, [r2, #4]
	adds r6, #1
	cmp r6, #1
	ble _080AA9E8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAA24: .4byte 0x000024BA
_080AAA28: .4byte 0x0000027D

	thumb_func_start FUN_080aaa2c
FUN_080aaa2c: @ 0x080AAA2C
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sl, r0
	ldr r0, _080AAAA4 @ =0x00001C1E
	bl GetParticleGroup
	adds r6, r0, #0
	movs r0, #0
	mov sb, r0
	movs r5, #0xb2
	lsls r5, r5, #1
	add r5, sl
	mov r8, r0
	movs r7, #7
_080AAA4E:
	movs r4, #0xcc
	lsls r4, r4, #1
	add r4, sl
	add r4, r8
	str r6, [r4]
	adds r0, r5, #0
	adds r1, r6, #0
	movs r2, #0x11
	bl FUN_0822d9f0
	adds r0, r5, #0
	movs r1, #4
	rsbs r1, r1, #0
	adds r2, r1, #0
	bl FUN_0822dad4
	ldr r1, [r4]
	adds r0, r5, #0
	movs r2, #2
	bl FUN_0822dafc
	adds r0, r5, #0
	movs r1, #1
	bl FUN_0822dadc
	mov r0, sb
	strb r0, [r5, #0xf]
	mov r0, sb
	strh r0, [r5, #0x28]
	strh r0, [r5, #0x2a]
	adds r5, #0x3c
	movs r0, #0x3c
	add r8, r0
	subs r7, #1
	cmp r7, #0
	bge _080AAA4E
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAAA4: .4byte 0x00001C1E

	thumb_func_start FUN_080aaaa8
FUN_080aaaa8: @ 0x080AAAA8
	push {r4, r5, r6, r7, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	adds r6, r4, #0
	adds r6, #0x94
	ldr r2, _080AAB08 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	ldr r3, _080AAB0C @ =0x00007530
	orrs r0, r3
	ldr r1, _080AAB10 @ =0x0000FFFF
	ands r0, r1
	ldr r1, _080AAB14 @ =0x75300000
	orrs r0, r1
	str r0, [sp, #0xc]
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	movs r0, #0
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	ldr r0, [r1, #4]
	ands r0, r2
	str r0, [r1, #4]
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	mov ip, r1
	cmp r0, #0
	bne _080AAB18
	ldr r1, [r4, #0x18]
	adds r0, r1, #0
	adds r0, #0x28
	movs r3, #1
	ldrb r0, [r0]
	lsls r3, r0
	adds r2, #0x1e
	adds r0, r1, r2
	ldrh r2, [r0]
	movs r0, #0xd9
	lsls r0, r0, #2
	adds r1, r1, r0
	ldrh r0, [r1]
	subs r5, r2, r0
	b _080AAB4E
	.align 2, 0
_080AAB08: .4byte 0xFFFF0000
_080AAB0C: .4byte 0x00007530
_080AAB10: .4byte 0x0000FFFF
_080AAB14: .4byte 0x75300000
_080AAB18:
	ldr r0, [r4, #0x18]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080AAB40
	ldr r0, _080AAB3C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r2, #0
	ldrsh r0, [r0, r2]
	adds r0, #0xa
	cmp r0, #0x63
	ble _080AAB4A
	movs r0, #0x63
	b _080AAB4A
	.align 2, 0
_080AAB3C: .4byte 0x030046A0
_080AAB40:
	ldr r0, _080AAB9C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r0, [r0, r1]
_080AAB4A:
	movs r3, #0
	lsls r5, r0, #3
_080AAB4E:
	movs r7, #0x80
	lsls r7, r7, #5
	ldr r2, _080AABA0 @ =0x00003001
	lsls r0, r3, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	add r0, sp, #0xc
	str r0, [sp, #4]
	mov r1, ip
	str r1, [sp, #8]
	adds r0, r6, #0
	movs r1, #0
	movs r3, #0
	bl FUN_0823646c
	str r7, [sp]
	movs r0, #0x1e
	str r0, [sp, #4]
	adds r0, r6, #0
	adds r1, r5, #0
	movs r2, #0xa
	movs r3, #0
	bl FUN_082364f8
	adds r0, r6, #0
	movs r1, #0
	adds r2, r4, #0
	bl FUN_0823651c
	ldr r1, [r4, #0x18]
	adds r1, #0x2c
	adds r0, r6, #0
	movs r2, #0
	bl FUN_082364c4
	add sp, #0x1c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AAB9C: .4byte 0x030046A0
_080AABA0: .4byte 0x00003001

	thumb_func_start FUN_080aaba4
FUN_080aaba4: @ 0x080AABA4
	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	str r1, [r5, #0x18]
	movs r1, #0xd2
	lsls r1, r1, #2
	adds r0, r5, r1
	strh r2, [r0]
	ldr r0, [r5, #0x18]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp]
	str r1, [sp, #4]
	ldr r2, [sp]
	asrs r1, r2, #0x10
	adds r1, #0x96
	lsls r1, r1, #0x10
	ldr r0, _080AABF4 @ =0x0000FFFF
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	adds r6, r5, #0
	adds r6, #0x84
	mov r7, sp
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x11
	ldrh r0, [r7, #4]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x11
	subs r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080AABF8
	asrs r0, r0, #8
	b _080AABFE
	.align 2, 0
_080AABF4: .4byte 0x0000FFFF
_080AABF8:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AABFE:
	strh r0, [r6]
	adds r1, r3, r2
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080AAC10
	asrs r0, r0, #8
	b _080AAC16
_080AAC10:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AAC16:
	adds r4, r0, #0
	movs r2, #2
	ldrsh r1, [r7, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #3
	cmp r0, #0
	blt _080AAC2A
	asrs r0, r0, #8
	b _080AAC30
_080AAC2A:
	rsbs r0, r0, #0
	asrs r0, r0, #8
	rsbs r0, r0, #0
_080AAC30:
	subs r2, r4, r0
	adds r4, r4, r0
	ldr r3, _080AAC74 @ =0x030047C8
	ldrh r0, [r6]
	ldrh r1, [r3]
	subs r0, r0, r1
	adds r0, #0x78
	strh r0, [r6]
	ldrh r0, [r3, #2]
	subs r2, r2, r0
	adds r2, #0x5a
	strh r2, [r6, #2]
	ldrh r0, [r3, #4]
	subs r4, r4, r0
	strh r4, [r6, #4]
	adds r0, r5, #0
	bl FUN_080aa940
	adds r0, r5, #0
	bl FUN_080aaa2c
	adds r0, r5, #0
	bl FUN_080aaaa8
	ldr r1, [r5, #0x18]
	ldr r2, _080AAC78 @ =0x00000359
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _080AAC7C
	adds r0, r1, #0
	adds r0, #0x90
	b _080AAC80
	.align 2, 0
_080AAC74: .4byte 0x030047C8
_080AAC78: .4byte 0x00000359
_080AAC7C:
	adds r0, r1, #0
	adds r0, #0xe8
_080AAC80:
	ldr r1, [r0]
	movs r2, #2
	rsbs r2, r2, #0
	ands r1, r2
	str r1, [r0]
	ldr r0, [r5, #0x18]
	movs r1, #0xd8
	lsls r1, r1, #1
	adds r0, r0, r1
	movs r4, #0
	strh r4, [r0]
	ldr r2, _080AACD8 @ =0x030047A4
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #4
	ldr r1, _080AACDC @ =0x030044BC
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0xd2
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080AACBC
	adds r0, r5, #0
	bl FUN_080aa9d0
_080AACBC:
	movs r1, #0xd3
	lsls r1, r1, #2
	adds r0, r5, r1
	ldr r1, _080AACE0 @ =FUN_080aa834
	str r1, [r0]
	ldr r2, _080AACE4 @ =0x0000034A
	adds r0, r5, r2
	strh r4, [r0]
	movs r0, #0
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080AACD8: .4byte 0x030047A4
_080AACDC: .4byte 0x030044BC
_080AACE0: .4byte FUN_080aa834
_080AACE4: .4byte 0x0000034A

	thumb_func_start FUN_080aace8
FUN_080aace8: @ 0x080AACE8
	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	movs r1, #0xd4
	lsls r1, r1, #2
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _080AAD28
	ldr r1, _080AAD20 @ =FUN_080aa8d8
	ldr r2, _080AAD24 @ =0x080AA8F9
	bl SetEntityRoutine
	adds r0, r4, #0
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_080aaba4
	cmp r0, #0
	bge _080AAD28
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _080AAD2A
	.align 2, 0
_080AAD20: .4byte FUN_080aa8d8
_080AAD24: .4byte 0x080AA8F9
_080AAD28:
	adds r0, r4, #0
_080AAD2A:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

