	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _0807131C @ =0x000009C8
	adds r5, r6, r0
	ldr r1, _08071320 @ =0x00000A8A
	adds r4, r6, r1
	ldrh r0, [r4]
	cmp r0, #0
	bne _080712EC
	ldr r0, _08071324 @ =0x00000391
	bl PlaySound_082406e0
_080712EC:
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bhi _0807139A
	ldr r2, _08071328 @ =0x085B0A08
	ldr r3, _0807132C @ =0x00000A8C
	adds r0, r6, r3
	ldrb r0, [r0]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _08071330
	asrs r1, r0, #0xc
	b _08071336
	.align 2, 0
_0807131C: .4byte 0x000009C8
_08071320: .4byte 0x00000A8A
_08071324: .4byte 0x00000391
_08071328: .4byte 0x085B0A08
_0807132C: .4byte 0x00000A8C
_08071330:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08071336:
	adds r0, r5, #0
	adds r0, #0xa0
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x98
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xa2
	ldrh r0, [r0]
	adds r1, #2
	strh r0, [r1]
	adds r0, r5, #0
	adds r0, #0xc4
	ldrb r0, [r0]
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0x64
	muls r0, r1, r0
	cmp r0, #0
	blt _08071368
	asrs r1, r0, #0xc
	b _0807136E
_08071368:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_0807136E:
	adds r0, r5, #0
	adds r0, #0xa4
	ldrh r0, [r0]
	adds r0, r0, r1
	adds r1, r5, #0
	adds r1, #0x9c
	strh r0, [r1]
	movs r3, #0xa1
	lsls r3, r3, #4
	adds r4, r6, r3
	movs r0, #0xa6
	lsls r0, r0, #4
	adds r1, r6, r0
	adds r0, r4, #0
	movs r2, #0
	bl FUN_082364c4
	adds r0, r4, #0
	bl FUN_08236400
	movs r0, #0
	b _080713A0
_0807139A:
	movs r0, #0
	strh r0, [r4]
	movs r0, #1
_080713A0:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
