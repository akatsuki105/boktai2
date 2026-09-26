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
