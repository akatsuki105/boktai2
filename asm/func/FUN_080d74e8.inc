	push {r4, r5, r6, lr}
	sub sp, #8
	adds r4, r0, #0
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	bne _080D754C
	lsls r0, r1, #2
	adds r0, r0, r1
	movs r1, #0x64
	bl Div
	adds r2, r0, #0
	cmp r2, #0
	bgt _080D7506
	movs r2, #1
_080D7506:
	movs r0, #0xda
	lsls r0, r0, #2
	adds r1, r4, r0
	ldrh r5, [r1]
	adds r3, r5, r2
	ldr r6, _080D7520 @ =0x0000036A
	adds r0, r4, r6
	ldrh r0, [r0]
	cmp r3, r0
	ble _080D7524
	subs r2, r0, r5
	strh r0, [r1]
	b _080D7526
	.align 2, 0
_080D7520: .4byte 0x0000036A
_080D7524:
	strh r3, [r1]
_080D7526:
	cmp r2, #0
	ble _080D754C
	movs r1, #0xb6
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r3, r4, #0
	adds r3, #0x2c
	movs r5, #0x97
	lsls r5, r5, #4
	adds r1, r4, r5
	str r1, [sp]
	ldr r6, _080D7554 @ =0x00000978
	adds r1, r4, r6
	ldrb r1, [r1]
	str r1, [sp, #4]
	adds r1, r2, #0
	movs r2, #1
	bl CreateDamageNumber
_080D754C:
	add sp, #8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080D7554: .4byte 0x00000978
