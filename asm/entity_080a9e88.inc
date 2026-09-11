	.include "asm/macros.inc"

	.syntax unified
	
	.text

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
