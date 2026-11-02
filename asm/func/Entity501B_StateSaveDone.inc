	push {r4, r5, r6, lr}
	sub sp, #0xc
	adds r5, r0, #0
	ldr r0, _081E0630 @ =0x000003E9
	adds r6, r5, r0
	ldrb r0, [r6]
	cmp r0, #0
	beq _081E060A
	movs r1, #0xf8
	lsls r1, r1, #2
	adds r4, r5, r1
	ldr r0, [r4]
	movs r2, #0xf6
	lsls r2, r2, #2
	adds r1, r5, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #7
	bl TextPanel_SetMessage
	ldr r0, _081E0634 @ =0x000002AE
	bl PlaySound_082406e0
	ldr r0, _081E0638 @ =0x000003EA
	adds r1, r5, r0
	movs r2, #0
	movs r0, #0
	strh r0, [r1]
	strb r2, [r6]
_081E060A:
	ldr r1, _081E0638 @ =0x000003EA
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x78
	bne _081E0640
	movs r0, #4
	str r0, [sp]
	ldr r0, _081E063C @ =0x0000FFFF
	str r0, [sp, #4]
	movs r0, #0
	str r0, [sp, #8]
	movs r0, #3
	movs r1, #4
	movs r2, #4
	movs r3, #4
	bl FUN_0823ce68
	b _081E064A
	.align 2, 0
_081E0630: .4byte 0x000003E9
_081E0634: .4byte 0x000002AE
_081E0638: .4byte 0x000003EA
_081E063C: .4byte 0x0000FFFF
_081E0640:
	cmp r0, #0x8c
	bls _081E064A
	bl FUN_081df940
	b _081E0654
_081E064A:
	ldr r2, _081E065C @ =0x000003EA
	adds r1, r5, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081E0654:
	add sp, #0xc
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081E065C: .4byte 0x000003EA
