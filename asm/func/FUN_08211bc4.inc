	push {r4, r5, r6, r7, lr}
	adds r5, r0, #0
	adds r6, r1, #0
	ldr r1, _08211BF0 @ =0x00000322
	adds r0, r5, r1
	movs r2, #0
	ldrsh r7, [r0, r2]
	cmp r7, #0
	bne _08211C3E
	movs r3, #0xa
	ldrsh r1, [r6, r3]
	cmp r1, #0x46
	bne _08211BF4
	adds r0, r5, #0
	movs r1, #3
	bl FUN_08211bac
	movs r1, #0xc6
	lsls r1, r1, #2
	adds r0, r5, r1
	b _08211C0A
	.align 2, 0
_08211BF0: .4byte 0x00000322
_08211BF4:
	movs r0, #1
	rsbs r0, r0, #0
	cmp r1, r0
	bne _08211C12
	adds r0, r5, #0
	movs r1, #4
	bl FUN_08211bac
	movs r2, #0xc6
	lsls r2, r2, #2
	adds r0, r5, r2
_08211C0A:
	ldr r0, [r0]
	bl FUN_0820fea8
	b _08211C82
_08211C12:
	movs r3, #0xc6
	lsls r3, r3, #2
	adds r4, r5, r3
	ldr r0, [r4]
	movs r2, #0xa
	ldrsh r1, [r6, r2]
	bl FUN_0820fe98
	ldr r0, [r4]
	bl FUN_0820feb0
	ldr r0, [r4]
	ldrh r1, [r6, #6]
	ldrh r2, [r6, #8]
	bl FUN_0820feb8
	ldr r0, _08211C64 @ =0x0300445C
	str r7, [r0]
	ldr r1, _08211C68 @ =0x03004464
	ldr r3, _08211C6C @ =0x00001084
	adds r0, r3, #0
	strh r0, [r1]
_08211C3E:
	ldr r0, _08211C70 @ =0x00000322
	adds r2, r5, r0
	ldrh r0, [r2]
	adds r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	asrs r0, r0, #0x10
	ldrh r1, [r6, #2]
	cmp r0, r1
	blt _08211C74
	ldr r1, _08211C64 @ =0x0300445C
	movs r0, #0x40
	str r0, [r1]
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08211bac
	b _08211C82
	.align 2, 0
_08211C64: .4byte 0x0300445C
_08211C68: .4byte 0x03004464
_08211C6C: .4byte 0x00001084
_08211C70: .4byte 0x00000322
_08211C74:
	movs r3, #0
	ldrsh r0, [r2, r3]
	lsls r0, r0, #6
	bl Div
	ldr r1, _08211C88 @ =0x0300445C
	str r0, [r1]
_08211C82:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08211C88: .4byte 0x0300445C
