	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r2, #0xce
	lsls r2, r2, #3
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r7, r1, r0
	ldr r1, _080AF464 @ =0x0000061C
	adds r0, r5, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	ldr r2, _080AF468 @ =0x00000674
	adds r0, r5, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r6, r1, r0
	adds r0, r7, #0
	adds r1, r6, #0
	bl ArcTan2_8
	adds r4, r0, #0
	lsls r1, r4, #4
	ldr r2, _080AF46C @ =0x0000067C
	adds r0, r5, r2
	movs r2, #0
	strh r1, [r0]
	ldr r1, _080AF470 @ =0x0000067E
	adds r0, r5, r1
	strh r2, [r0]
	adds r0, r4, #0
	subs r0, #0x20
	cmp r0, #0x3f
	bls _080AF454
	subs r0, #0x80
	cmp r0, #0x3f
	bhi _080AF478
_080AF454:
	lsls r0, r6, #0xc
	ldr r2, _080AF474 @ =0x085B0A08
	movs r1, #0xff
	ands r1, r4
	lsls r1, r1, #1
	adds r1, r1, r2
	b _080AF488
	.align 2, 0
_080AF464: .4byte 0x0000061C
_080AF468: .4byte 0x00000674
_080AF46C: .4byte 0x0000067C
_080AF470: .4byte 0x0000067E
_080AF474: .4byte 0x085B0A08
_080AF478:
	lsls r0, r7, #0xc
	ldr r3, _080AF49C @ =0x085B0A08
	adds r1, r4, #0
	adds r1, #0x40
	movs r2, #0xff
	ands r1, r2
	lsls r1, r1, #1
	adds r1, r1, r3
_080AF488:
	movs r2, #0
	ldrsh r1, [r1, r2]
	bl Div
	ldr r2, _080AF4A0 @ =0x00000684
	adds r1, r5, r2
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AF49C: .4byte 0x085B0A08
_080AF4A0: .4byte 0x00000684
