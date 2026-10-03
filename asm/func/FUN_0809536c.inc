	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r7, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	movs r1, #0xd6
	lsls r1, r1, #2
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #5
	bne _080953DC
	ldr r0, _080953CC @ =0x000015CC
	adds r2, r7, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r1, _080953D0 @ =0x000015C4
	adds r4, r7, r1
	adds r1, r7, #0
	adds r1, #0xa0
	adds r0, r4, #0
	movs r2, #0x3c
	movs r3, #1
	bl MainSprite_SetPose
	ldr r1, _080953D4 @ =0x000002DF
	adds r0, r4, #0
	bl FUN_0808ba0c
	movs r2, #1
	ldr r0, _080953D8 @ =0x0000162C
	adds r1, r7, r0
	movs r6, #0xe
_080953BA:
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r1, #0x60
	subs r6, #1
	cmp r6, #0
	bge _080953BA
	b _0809549A
	.align 2, 0
_080953CC: .4byte 0x000015CC
_080953D0: .4byte 0x000015C4
_080953D4: .4byte 0x000002DF
_080953D8: .4byte 0x0000162C
_080953DC:
	movs r6, #0
	ldr r1, _08095404 @ =0x000015C4
	adds r5, r7, r1
	movs r0, #0xcc
	lsls r0, r0, #3
	mov r8, r0
_080953E8:
	adds r0, r6, #0
	bl GetWeaponID
	adds r4, r0, #0
	cmp r4, #0
	bne _0809540C
	ldr r1, _08095408 @ =0x00000F6C
	adds r0, r7, r1
	add r0, r8
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
	b _0809548E
	.align 2, 0
_08095404: .4byte 0x000015C4
_08095408: .4byte 0x00000F6C
_0809540C:
	ldr r0, _08095450 @ =0x00000F6C
	adds r2, r7, r0
	add r2, r8
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	lsls r2, r4, #0x10
	lsrs r2, r2, #0x10
	adds r0, r5, #0
	adds r1, r7, #0
	adds r1, #0xa0
	movs r3, #1
	bl MainSprite_SetPose
	ldr r3, _08095454 @ =0x000002DF
	adds r0, r5, #0
	adds r1, r3, #0
	str r3, [sp]
	bl FUN_0808ba0c
	ldr r3, [sp]
	cmp r4, #0x3a
	beq _08095442
	cmp r4, #0x3e
	bne _08095458
_08095442:
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
	b _0809548E
	.align 2, 0
_08095450: .4byte 0x00000F6C
_08095454: .4byte 0x000002DF
_08095458:
	ldr r0, _0809547C @ =0x030046A0
	ldr r0, [r0]
	adds r0, #0x40
	movs r1, #0
	ldrsh r2, [r0, r1]
	ldr r1, _08095480 @ =0x08DA9E68
	lsls r0, r4, #3
	adds r0, r0, r4
	lsls r0, r0, #2
	adds r0, r0, r1
	ldrb r0, [r0, #3]
	cmp r2, r0
	blt _08095484
	adds r0, r5, #0
	adds r1, r3, #0
	bl FUN_0808ba0c
	b _0809548E
	.align 2, 0
_0809547C: .4byte 0x030046A0
_08095480: .4byte 0x08DA9E68
_08095484:
	adds r0, r5, #0
	movs r1, #0xb8
	lsls r1, r1, #2
	bl FUN_0808ba0c
_0809548E:
	adds r5, #0x60
	movs r0, #0x60
	add r8, r0
	adds r6, #1
	cmp r6, #0xf
	ble _080953E8
_0809549A:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
