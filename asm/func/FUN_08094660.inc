	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _08094698 @ =0x000009EE
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	bne _08094676
	movs r0, #0x87
	lsls r0, r0, #1
	bl PlaySound_082406e0
_08094676:
	ldrh r0, [r4]
	adds r1, r0, #1
	strh r1, [r4]
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xb
	bhi _080946B8
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x11
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	beq _080946A0
	ldr r2, _0809469C @ =0x00001BE6
	adds r1, r5, r2
	b _080946C4
	.align 2, 0
_08094698: .4byte 0x000009EE
_0809469C: .4byte 0x00001BE6
_080946A0:
	ldrh r1, [r4]
	movs r0, #0x14
	subs r0, r0, r1
	asrs r0, r0, #3
	movs r1, #0x46
	subs r1, r1, r0
	ldr r2, _080946B4 @ =0x00001BE6
	adds r0, r5, r2
	strh r1, [r0]
	b _080946D6
	.align 2, 0
_080946B4: .4byte 0x00001BE6
_080946B8:
	lsls r0, r1, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0xf
	bhi _080946D0
	ldr r0, _080946CC @ =0x00001BE6
	adds r1, r5, r0
_080946C4:
	movs r0, #0x46
	strh r0, [r1]
	b _080946D6
	.align 2, 0
_080946CC: .4byte 0x00001BE6
_080946D0:
	adds r0, r5, #0
	bl FUN_08092744
_080946D6:
	pop {r4, r5}
	pop {r0}
	bx r0
