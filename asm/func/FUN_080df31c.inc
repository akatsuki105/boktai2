	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0x40
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _080DF3A6
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _080DF370 @ =0x030047A4
	ldr r1, _080DF374 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _080DF3A6
	movs r1, #4
	ldr r0, _080DF378 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _080DF3A6
	adds r0, r4, #0
	bl FUN_080de344
	movs r7, #0
	ldr r0, _080DF37C @ =0x085AD354
	mov r8, r0
	movs r0, #0x9b
	lsls r0, r0, #1
	adds r6, r4, r0
_080DF360:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _080DF380
	movs r0, #1
	b _080DF382
	.align 2, 0
_080DF370: .4byte 0x030047A4
_080DF374: .4byte 0x030047A0
_080DF378: .4byte 0x03002BC0
_080DF37C: .4byte 0x085AD354
_080DF380:
	movs r0, #0
_080DF382:
	cmp r0, #0
	beq _080DF396
	ldrb r0, [r6]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
_080DF396:
	adds r6, #0xfc
	adds r5, #0xfc
	adds r7, #1
	cmp r7, #0x17
	ble _080DF360
	ldrh r0, [r4, #0x3c]
	adds r0, #1
	strh r0, [r4, #0x3c]
_080DF3A6:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
