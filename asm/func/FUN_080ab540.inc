	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	mov sb, r0
	mov r8, r1
	ldr r3, _080AB5CC @ =0x0203B400
	ldr r1, _080AB5D0 @ =0x030046B8
	ldr r0, [r1]
	adds r0, #1
	ldr r2, _080AB5D4 @ =0x000003FF
	ands r0, r2
	str r0, [r1]
	lsls r0, r0, #1
	adds r0, r0, r3
	ldrb r6, [r0]
	movs r4, #0xac
	lsls r4, r4, #1
	add r4, sb
	movs r5, #0xa0
	lsls r5, r5, #1
	add r5, sb
	adds r7, r5, #0
	movs r0, #0xb
	mov sl, r0
_080AB574:
	movs r0, #1
	strb r0, [r4, #0x10]
	ldr r2, _080AB5D0 @ =0x030046B8
	ldr r1, [r2]
	adds r1, #1
	ldr r0, _080AB5D4 @ =0x000003FF
	ands r1, r0
	lsls r0, r1, #1
	ldr r2, _080AB5CC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r2, #0xf
	ands r0, r2
	adds r0, r0, r6
	subs r0, #9
	strb r0, [r4, #0x12]
	adds r1, #1
	ldr r0, _080AB5D4 @ =0x000003FF
	ands r1, r0
	ldr r2, _080AB5D0 @ =0x030046B8
	str r1, [r2]
	lsls r1, r1, #1
	ldr r0, _080AB5CC @ =0x0203B400
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r1, #0xf
	ands r0, r1
	adds r0, #0x19
	strh r0, [r4, #0x16]
	ldrh r3, [r4, #0x16]
	ldr r2, _080AB5D8 @ =0x085B0A08
	ldrb r0, [r4, #0x12]
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r3, r0
	cmp r0, #0
	blt _080AB5DC
	asrs r0, r0, #0xc
	b _080AB5E2
	.align 2, 0
_080AB5CC: .4byte 0x0203B400
_080AB5D0: .4byte 0x030046B8
_080AB5D4: .4byte 0x000003FF
_080AB5D8: .4byte 0x085B0A08
_080AB5DC:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AB5E2:
	strh r0, [r4, #0x20]
	movs r2, #0
	strh r2, [r4, #0x22]
	ldrh r0, [r4, #0x16]
	ldrb r1, [r4, #0x12]
	lsls r1, r1, #1
	ldr r2, _080AB600 @ =0x085B0A08
	adds r1, r1, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	muls r0, r1, r0
	cmp r0, #0
	blt _080AB604
	asrs r0, r0, #0xc
	b _080AB60A
	.align 2, 0
_080AB600: .4byte 0x085B0A08
_080AB604:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_080AB60A:
	strh r0, [r4, #0x24]
	ldr r0, _080AB678 @ =FUN_080ab4e8
	str r0, [r4, #0x28]
	movs r0, #0
	strh r0, [r4, #0x14]
	ldr r0, [r5]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r5]
	movs r0, #0x9e
	lsls r0, r0, #1
	add r0, sb
	ldr r1, [r0]
	ldrb r2, [r4, #0x11]
	adds r0, r7, #0
	bl FUN_0822dafc
	ldrh r0, [r4, #0x20]
	mov r1, r8
	ldrh r1, [r1]
	adds r0, r0, r1
	strh r0, [r4]
	mov r2, r8
	ldrh r0, [r2, #2]
	strh r0, [r4, #2]
	ldrh r0, [r4, #0x24]
	ldrh r1, [r2, #4]
	adds r0, r0, r1
	strh r0, [r4, #4]
	movs r1, #1
	strb r1, [r5, #0xf]
	adds r6, #0x18
	movs r0, #0xff
	ands r6, r0
	adds r4, #0x44
	adds r5, #0x44
	adds r7, #0x44
	movs r2, #1
	rsbs r2, r2, #0
	add sl, r2
	mov r0, sl
	cmp r0, #0
	bge _080AB574
	movs r0, #0x9d
	lsls r0, r0, #1
	add r0, sb
	strb r1, [r0]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080AB678: .4byte FUN_080ab4e8
