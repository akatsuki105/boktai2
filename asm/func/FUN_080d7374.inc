	push {r4, r5, lr}
	adds r5, r0, #0
	movs r0, #0xa8
	lsls r0, r0, #0xb
	ldr r1, [r5, #0x20]
	orrs r1, r0
	str r1, [r5, #0x20]
	ldr r0, [r5, #0x1c]
	cmp r0, #1
	beq _080D738E
	cmp r0, #2
	beq _080D7420
	b _080D743C
_080D738E:
	movs r0, #0x10
	ands r1, r0
	cmp r1, #0
	beq _080D73B6
	ldr r1, [r5, #0x18]
	ldr r0, _080D73A4 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D73A8
	movs r0, #0
	b _080D73AE
	.align 2, 0
_080D73A4: .4byte 0x03002C68
_080D73A8:
	adds r0, #0x60
	adds r0, r0, r1
	ldrb r0, [r0]
_080D73AE:
	adds r1, r0, #0
	adds r0, r5, #0
	bl FUN_080d0394
_080D73B6:
	adds r0, r5, #0
	bl FUN_080d6600
	adds r0, r5, #0
	bl FUN_080d7210
	adds r4, r0, #0
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_080cfaa4
	ldr r0, _080D7418 @ =0x085AD280
	lsls r4, r4, #2
	adds r4, r4, r0
	ldr r1, [r4]
	adds r0, r5, #0
	bl _call_via_r1
	movs r1, #0xe9
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080D73F2
	adds r1, #4
	adds r0, r5, r1
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r5, #0x34]
	str r1, [r5, #0x38]
_080D73F2:
	adds r0, r5, #0
	bl FUN_080d72a8
	ldr r1, _080D741C @ =0x000003CE
	adds r0, r5, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	beq _080D740A
	adds r0, r5, #0
	bl FUN_080cfb20
_080D740A:
	adds r0, r5, #0
	bl FUN_080cfcb0
	adds r0, r5, #0
	bl FUN_080d01c8
	b _080D743C
	.align 2, 0
_080D7418: .4byte 0x085AD280
_080D741C: .4byte 0x000003CE
_080D7420:
	adds r0, r5, #0
	movs r1, #8
	bl FUN_080cc3c4
	movs r1, #0x93
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	adds r0, r5, #0
	bl FUN_080d72a8
_080D743C:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
