	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r6, r0, #0
	adds r0, #0x58
	ldrh r0, [r0]
	cmp r0, #5
	bls _080DD512
	b _080DD6E6
_080DD512:
	lsls r0, r0, #2
	ldr r1, _080DD51C @ =_080DD520
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080DD51C: .4byte _080DD520
_080DD520: @ jump table
	.4byte _080DD538 @ case 0
	.4byte _080DD570 @ case 1
	.4byte _080DD5B4 @ case 2
	.4byte _080DD5FC @ case 3
	.4byte _080DD644 @ case 4
	.4byte _080DD6A4 @ case 5
_080DD538:
	ldr r0, [r6, #0x60]
	cmp r0, #0
	bne _080DD544
	ldr r0, _080DD56C @ =0x00000165
	bl PlaySound_082406e0
_080DD544:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
_080DD54A:
	lsls r3, r5, #6
	movs r0, #0x54
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #5
	ble _080DD54A
	b _080DD6E6
	.align 2, 0
_080DD56C: .4byte 0x00000165
_080DD570:
	movs r5, #0
	adds r7, r6, #0
	adds r7, #0x50
	movs r0, #1
	mov r8, r0
_080DD57A:
	lsls r4, r5, #6
	movs r0, #0x22
	str r0, [sp]
	mov r1, r8
	str r1, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #8
	adds r3, r4, #0
	bl FUN_081eec74
	movs r0, #0x40
	str r0, [sp]
	mov r0, r8
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r7, #0
	movs r1, #1
	movs r2, #0xe
	adds r3, r4, #0
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #3
	ble _080DD57A
	b _080DD6E6
_080DD5B4:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	ldr r7, _080DD5F0 @ =0x030046B8
_080DD5BC:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DD5F4 @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DD5F8 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0xf
	ands r2, r0
	lsls r3, r5, #6
	movs r0, #0x96
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #5
	ble _080DD5BC
	b _080DD6E6
	.align 2, 0
_080DD5F0: .4byte 0x030046B8
_080DD5F4: .4byte 0x000003FF
_080DD5F8: .4byte 0x0203B400
_080DD5FC:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	ldr r7, _080DD638 @ =0x030046B8
_080DD604:
	ldr r0, [r7]
	adds r0, #1
	ldr r1, _080DD63C @ =0x000003FF
	ands r0, r1
	str r0, [r7]
	lsls r0, r0, #1
	ldr r1, _080DD640 @ =0x0203B400
	adds r0, r0, r1
	ldrh r2, [r0]
	movs r0, #0x1f
	ands r2, r0
	lsls r3, r5, #5
	movs r0, #0x64
	str r0, [sp]
	movs r0, #1
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #7
	ble _080DD604
	b _080DD6E6
	.align 2, 0
_080DD638: .4byte 0x030046B8
_080DD63C: .4byte 0x000003FF
_080DD640: .4byte 0x0203B400
_080DD644:
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	ldr r0, _080DD698 @ =0x0203B400
	mov sb, r0
	ldr r1, _080DD69C @ =0x030046B8
	mov r8, r1
	ldr r7, _080DD6A0 @ =0x000003FF
_080DD654:
	mov r0, r8
	ldr r1, [r0]
	adds r1, #1
	ands r1, r7
	lsls r0, r1, #1
	add r0, sb
	ldrh r2, [r0]
	movs r0, #0xf
	ands r2, r0
	adds r2, #5
	adds r1, #1
	ands r1, r7
	mov r0, r8
	str r1, [r0]
	lsls r1, r1, #1
	add r1, sb
	ldrh r1, [r1]
	movs r0, #0x3f
	ands r1, r0
	adds r1, #0x50
	lsls r3, r5, #4
	str r1, [sp]
	movs r0, #2
	str r0, [sp, #4]
	ldr r0, [r6, #0x60]
	str r0, [sp, #8]
	adds r0, r4, #0
	movs r1, #1
	bl FUN_081eec74
	adds r5, #1
	cmp r5, #0xf
	ble _080DD654
	b _080DD6E6
	.align 2, 0
_080DD698: .4byte 0x0203B400
_080DD69C: .4byte 0x030046B8
_080DD6A0: .4byte 0x000003FF
_080DD6A4:
	ldr r0, [r6, #0x60]
	cmp r0, #0
	bne _080DD6E6
	movs r7, #2
	movs r5, #0
	adds r4, r6, #0
	adds r4, #0x50
	movs r6, #8
_080DD6B4:
	movs r0, #0xc
	str r0, [sp]
	movs r0, #0x12
	str r0, [sp, #4]
	lsls r0, r5, #5
	str r0, [sp, #8]
	str r6, [sp, #0xc]
	movs r0, #0x40
	str r0, [sp, #0x10]
	movs r0, #1
	str r0, [sp, #0x14]
	str r7, [sp, #0x18]
	movs r0, #0x80
	lsls r0, r0, #2
	str r0, [sp, #0x1c]
	str r6, [sp, #0x20]
	adds r0, r4, #0
	movs r1, #8
	movs r2, #0x10
	movs r3, #4
	bl FUN_081ee4ec
	adds r5, #1
	cmp r5, #7
	ble _080DD6B4
_080DD6E6:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
