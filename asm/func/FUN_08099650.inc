	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	movs r3, #0xd6
	lsls r3, r3, #2
	adds r0, r0, r3
	ldrb r0, [r0]
	movs r6, #0
	cmp r0, #0
	beq _08099672
	movs r6, #1
	cmp r0, #5
	bne _08099672
	movs r6, #2
_08099672:
	movs r0, #0
	movs r1, #6
	movs r2, #3
	bl FUN_0808a420
	adds r2, r0, #0
	lsls r0, r6, #1
	ldr r1, _080996BC @ =0x085ACFB8
	adds r0, r0, r6
	lsls r0, r0, #2
	movs r3, #0xf0
	lsls r3, r3, #8
	adds r4, r3, #0
	adds r1, r0, r1
	movs r3, #0xa
_08099690:
	ldrb r0, [r1]
	orrs r0, r4
	strh r0, [r2]
	adds r2, #2
	adds r1, #1
	subs r3, #1
	cmp r3, #0
	bge _08099690
	ldr r0, _080996C0 @ =0x00004014
	adds r4, r5, r0
	ldr r0, [r4]
	ldr r1, [r5, #0x58]
	bl TextPanel_SetScript
	cmp r6, #2
	bne _080996C4
	ldr r0, [r4]
	movs r1, #1
	bl TextPanel_SetMessage
	b _080996CC
	.align 2, 0
_080996BC: .4byte 0x085ACFB8
_080996C0: .4byte 0x00004014
_080996C4:
	ldr r0, [r4]
	movs r1, #0
	bl TextPanel_SetMessage
_080996CC:
	ldr r1, _080996DC @ =0x00004014
	adds r0, r5, r1
	ldr r0, [r0]
	bl TextPanel_Start
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080996DC: .4byte 0x00004014
