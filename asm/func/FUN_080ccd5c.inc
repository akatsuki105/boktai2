	push {r4, r5, r6, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r0, _080CCD9C @ =0x000006AC
	adds r3, r4, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r5, r0, #5
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r3, #0x1c]
	str r1, [r3, #0x20]
	ldr r2, _080CCDA0 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r6, #0
	ldrsh r1, [r0, r6]
	movs r0, #0xb4
	muls r0, r1, r0
	cmp r0, #0
	blt _080CCDA4
	asrs r1, r0, #0xc
	b _080CCDAA
	.align 2, 0
_080CCD9C: .4byte 0x000006AC
_080CCDA0: .4byte gSineTable
_080CCDA4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCDAA:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r0, #0xb4
	muls r0, r1, r0
	cmp r0, #0
	blt _080CCDC4
	asrs r1, r0, #0xc
	b _080CCDCA
_080CCDC4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCDCA:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	movs r2, #0
	strh r0, [r3, #0x20]
	movs r3, #0xe1
	lsls r3, r3, #3
	adds r0, r4, r3
	strh r2, [r0]
	ldr r6, _080CCE04 @ =0x0000070C
	adds r0, r4, r6
	strh r2, [r0]
	ldr r1, _080CCE08 @ =0x000006F4
	adds r0, r4, r1
	subs r3, #4
	adds r1, r4, r3
	ldr r1, [r1]
	str r2, [sp]
	movs r2, #2
	movs r3, #0
	bl AuxAnim_SetAnim
	adds r0, r4, #0
	bl FUN_080ccae0
	add sp, #4
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080CCE04: .4byte 0x0000070C
_080CCE08: .4byte 0x000006F4
