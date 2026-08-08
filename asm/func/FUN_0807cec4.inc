	push {r4, r5, r6, lr}
	sub sp, #0x10
	adds r5, r0, #0
	adds r4, r2, #0
	adds r6, r3, #0
	cmp r1, #8
	bls _0807CED4
	b _0807D106
_0807CED4:
	lsls r0, r1, #2
	ldr r1, _0807CEE0 @ =_0807CEE4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_0807CEE0: .4byte _0807CEE4
_0807CEE4: @ jump table
	.4byte _0807CF08 @ case 0
	.4byte _0807CF4C @ case 1
	.4byte _0807CF80 @ case 2
	.4byte _0807CFC0 @ case 3
	.4byte _0807D004 @ case 4
	.4byte _0807D03C @ case 5
	.4byte _0807D070 @ case 6
	.4byte _0807D0A4 @ case 7
	.4byte _0807D0DC @ case 8
_0807CF08:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r3, #0
	strb r3, [r2]
	ldr r1, _0807CF40 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	ldr r6, _0807CF44 @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #1
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _0807CF48 @ =0x000001B1
	bl PlaySound_082406e0
	b _0807D106
	.align 2, 0
_0807CF40: .4byte 0x00000992
_0807CF44: .4byte 0x0000098C
_0807CF48: .4byte 0x000001B1
_0807CF4C:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r3, #0
	strb r3, [r2]
	ldr r1, _0807CF78 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	ldr r6, _0807CF7C @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #3
	b _0807CFA8
	.align 2, 0
_0807CF78: .4byte 0x00000992
_0807CF7C: .4byte 0x0000098C
_0807CF80:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r3, #0
	strb r3, [r2]
	ldr r1, _0807CFB8 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	ldr r6, _0807CFBC @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0
_0807CFA8:
	bl FUN_080da9c4
	str r0, [r4]
	movs r0, #0xf6
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0807D106
	.align 2, 0
_0807CFB8: .4byte 0x00000992
_0807CFBC: .4byte 0x0000098C
_0807CFC0:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r3, #0
	strb r3, [r2]
	ldr r1, _0807CFF8 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	ldr r6, _0807CFFC @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #2
	bl FUN_080da9c4
	str r0, [r4]
	ldr r0, _0807D000 @ =0x000001ED
	bl PlaySound_082406e0
	b _0807D106
	.align 2, 0
_0807CFF8: .4byte 0x00000992
_0807CFFC: .4byte 0x0000098C
_0807D000: .4byte 0x000001ED
_0807D004:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r0, #1
	strb r0, [r2]
	ldr r1, _0807D034 @ =0x00000992
	adds r3, r5, r1
	strh r4, [r3]
	ldr r0, _0807D038 @ =0x0000098C
	adds r4, r5, r0
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	str r3, [sp, #4]
	movs r3, #0x96
	str r3, [sp, #8]
	movs r3, #0xe6
	str r3, [sp, #0xc]
	movs r3, #0
	b _0807D100
	.align 2, 0
_0807D034: .4byte 0x00000992
_0807D038: .4byte 0x0000098C
_0807D03C:
	movs r1, #0x99
	lsls r1, r1, #4
	adds r2, r5, r1
	movs r0, #3
	strb r0, [r2]
	ldr r0, _0807D06C @ =0x00000992
	adds r3, r5, r0
	strh r4, [r3]
	subs r1, #4
	adds r4, r5, r1
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	lsls r3, r6, #0x10
	asrs r3, r3, #0x10
	str r3, [sp, #4]
	movs r3, #0x96
	str r3, [sp, #8]
	movs r3, #0xe6
	str r3, [sp, #0xc]
	movs r3, #0
	b _0807D100
	.align 2, 0
_0807D06C: .4byte 0x00000992
_0807D070:
	movs r6, #0x99
	lsls r6, r6, #4
	adds r2, r5, r6
	movs r3, #0
	movs r0, #5
	strb r0, [r2]
	ldr r1, _0807D0A0 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	subs r6, #4
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	str r3, [sp, #8]
	movs r3, #0xe6
	str r3, [sp, #0xc]
	movs r3, #0
	b _0807D100
	.align 2, 0
_0807D0A0: .4byte 0x00000992
_0807D0A4:
	movs r0, #0x99
	lsls r0, r0, #4
	adds r2, r5, r0
	movs r3, #0
	movs r0, #4
	strb r0, [r2]
	ldr r1, _0807D0D4 @ =0x00000992
	adds r0, r5, r1
	strh r3, [r0]
	ldr r6, _0807D0D8 @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	movs r3, #0x96
	str r3, [sp, #8]
	movs r3, #0xe6
	str r3, [sp, #0xc]
	movs r3, #0
	b _0807D100
	.align 2, 0
_0807D0D4: .4byte 0x00000992
_0807D0D8: .4byte 0x0000098C
_0807D0DC:
	ldr r1, _0807D110 @ =0x00000992
	adds r0, r5, r1
	movs r3, #0
	strh r3, [r0]
	ldr r6, _0807D114 @ =0x0000098C
	adds r4, r5, r6
	ldr r0, [r4]
	adds r1, r5, #0
	adds r1, #0x24
	adds r6, #4
	adds r2, r5, r6
	ldrb r2, [r2]
	str r3, [sp]
	str r3, [sp, #4]
	str r3, [sp, #8]
	movs r3, #0x50
	str r3, [sp, #0xc]
	movs r3, #0x7f
_0807D100:
	bl FUN_080da9c4
	str r0, [r4]
_0807D106:
	add sp, #0x10
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_0807D110: .4byte 0x00000992
_0807D114: .4byte 0x0000098C
