	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #0x14
	adds r6, r0, #0
	adds r7, r1, #0
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	adds r1, r6, #0
	adds r1, #0xa9
	ldrb r0, [r1]
	cmp r0, #0
	beq _0802739C
	movs r4, #0
	strb r4, [r1]
	movs r2, #0x96
	lsls r2, r2, #2
	adds r1, r6, r2
	movs r3, #0x8e
	lsls r3, r3, #2
	adds r2, r6, r3
	movs r5, #1
	str r5, [sp]
	str r4, [sp, #4]
	adds r0, r6, #0
	movs r3, #0x11
	bl Boss_PlayAnimFlip
	adds r2, r6, #0
	adds r2, #0xcc
	mov r3, r8
	ldr r0, [r3, #8]
	ldr r1, [r3, #0xc]
	str r0, [r2]
	str r1, [r2, #4]
	movs r2, #0x10
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r1, _080273E4 @ =0x000004D4
	adds r0, r6, r1
	movs r1, #0x30
	str r1, [sp]
	ldr r1, _080273E8 @ =0x00001964
	str r1, [sp, #4]
	movs r1, #0x64
	str r1, [sp, #8]
	movs r1, #6
	str r1, [sp, #0xc]
	str r5, [sp, #0x10]
	movs r1, #0x30
	movs r2, #0x30
	movs r3, #0x30
	bl AuxShadow_SetScaleParams
	movs r2, #0xac
	lsls r2, r2, #1
	adds r1, r6, r2
	movs r0, #0x80
	lsls r0, r0, #1
	strh r0, [r1]
	movs r3, #0xad
	lsls r3, r3, #1
	adds r0, r6, r3
	strh r4, [r0]
	movs r0, #0xca
	lsls r0, r0, #2
	bl PlaySound_0824078c
_0802739C:
	movs r0, #0xa8
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #0
	strh r0, [r1]
	ldr r2, _080273EC @ =0x0001000C
	adds r1, r6, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r1, #0x80
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	adds r0, r6, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08027446
	adds r0, r6, #0
	adds r0, #0xcc
	ldr r1, [r0, #4]
	ldr r0, [r0]
	mov r2, r8
	str r0, [r2, #8]
	str r1, [r2, #0xc]
	cmp r7, #0x1f
	ble _080273F0
	adds r1, r6, #0
	adds r1, #0xa7
	movs r0, #1
	strb r0, [r1]
	b _08027446
	.align 2, 0
_080273E4: .4byte 0x000004D4
_080273E8: .4byte 0x00001964
_080273EC: .4byte 0x0001000C
_080273F0:
	movs r1, #3
	bics r1, r7
	movs r0, #0x20
	subs r0, r0, r7
	adds r4, r6, #0
	adds r4, #0x58
	lsls r5, r1, #6
	lsls r6, r0, #3
	ldr r2, _0802741C @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r0, [r0, r3]
	muls r0, r6, r0
	cmp r0, #0
	blt _08027420
	asrs r3, r0, #0xc
	b _08027426
	.align 2, 0
_0802741C: .4byte gSineTable
_08027420:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r3, r0, #0
_08027426:
	movs r0, #0
	strh r3, [r4]
	strh r0, [r4, #2]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r6, r0
	cmp r0, #0
	blt _0802743E
	asrs r0, r0, #0xc
	b _08027444
_0802743E:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08027444:
	strh r0, [r4, #4]
_08027446:
	add sp, #0x14
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
