	push {r4, r5, r6, r7, lr}
	sub sp, #0xc
	adds r4, r0, #0
	adds r6, r1, #0
	ldr r0, _080CCB6C @ =0x000006AC
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
	ldrh r0, [r3, #0x1e]
	adds r0, #0xbe
	strh r0, [r3, #0x1e]
	ldr r2, _080CCB70 @ =gSineTable
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080CCB74
	asrs r1, r0, #0xc
	b _080CCB7A
	.align 2, 0
_080CCB6C: .4byte 0x000006AC
_080CCB70: .4byte gSineTable
_080CCB74:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCB7A:
	ldrh r0, [r3, #0x1c]
	adds r0, r0, r1
	strh r0, [r3, #0x1c]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r7, #0
	ldrsh r1, [r0, r7]
	lsls r0, r1, #4
	subs r0, r0, r1
	lsls r0, r0, #4
	cmp r0, #0
	blt _080CCB96
	asrs r1, r0, #0xc
	b _080CCB9C
_080CCB96:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCB9C:
	ldrh r0, [r3, #0x20]
	adds r0, r0, r1
	strh r0, [r3, #0x20]
	adds r0, r5, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r3, #0
	ldrsh r1, [r0, r3]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCBC0
	asrs r1, r0, #0xc
	b _080CCBC6
_080CCBC0:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_080CCBC6:
	movs r7, #0xe1
	lsls r7, r7, #3
	adds r0, r4, r7
	strh r1, [r0]
	lsls r0, r5, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #1
	cmp r0, #0
	blt _080CCBE4
	asrs r2, r0, #0xc
	b _080CCBEA
_080CCBE4:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r2, r0, #0
_080CCBEA:
	ldr r3, _080CCC28 @ =0x0000070C
	adds r0, r4, r3
	strh r2, [r0]
	add r2, sp, #8
	adds r0, r6, #0
	add r1, sp, #4
	bl FUN_080ccaa0
	ldr r7, _080CCC2C @ =0x000006F4
	adds r0, r4, r7
	ldr r2, _080CCC30 @ =0x00000704
	adds r1, r4, r2
	ldr r1, [r1]
	ldr r3, [sp, #4]
	lsls r3, r3, #0x18
	lsrs r3, r3, #0x18
	ldr r2, [sp, #8]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	str r2, [sp]
	movs r2, #0
	bl AuxAnim_SetAnim
	adds r0, r4, #0
	bl FUN_080ccae0
	add sp, #0xc
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080CCC28: .4byte 0x0000070C
_080CCC2C: .4byte 0x000006F4
_080CCC30: .4byte 0x00000704
