	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	bl FUN_0822d00c
	ldr r1, _0822D860 @ =0x03004468
	str r0, [r1]
	movs r3, #0
	ldr r0, _0822D864 @ =0x03004470
	mov sl, r0
	ldr r1, _0822D868 @ =gObjectPlttBuffer
	mov sb, r1
_0822D844:
	ldr r0, _0822D86C @ =0x03004458
	ldr r0, [r0]
	cmp r3, r0
	bge _0822D874
	lsls r2, r3, #1
	mov r4, sl
	adds r0, r2, r4
	ldrh r0, [r0]
	lsls r0, r0, #5
	ldr r4, _0822D870 @ =0x03003584
	ldr r1, [r4]
	adds r4, r1, r0
	lsls r0, r3, #5
	b _0822D87C
	.align 2, 0
_0822D860: .4byte 0x03004468
_0822D864: .4byte 0x03004470
_0822D868: .4byte gObjectPlttBuffer
_0822D86C: .4byte 0x03004458
_0822D870: .4byte 0x03003584
_0822D874:
	lsls r0, r3, #5
	mov r1, sb
	adds r4, r0, r1
	lsls r2, r3, #1
_0822D87C:
	mov r1, sb
	adds r5, r0, r1
	mov r1, sl
	adds r0, r2, r1
	ldrh r0, [r0]
	adds r7, r3, #1
	ldr r1, _0822D8E4 @ =0x000002FA
	cmp r0, r1
	beq _0822D8D0
	movs r0, #0xf8
	lsls r0, r0, #2
	mov r8, r0
	movs r1, #0xf8
	lsls r1, r1, #7
	mov ip, r1
	movs r6, #0xf
_0822D89C:
	ldrh r3, [r4]
	movs r2, #0x1f
	ands r2, r3
	mov r1, r8
	ands r1, r3
	lsrs r1, r1, #5
	mov r0, ip
	ands r0, r3
	lsrs r0, r0, #0xa
	adds r2, r2, r1
	adds r2, r2, r0
	asrs r1, r2, #2
	asrs r0, r2, #4
	adds r1, r1, r0
	asrs r0, r2, #6
	adds r2, r1, r0
	lsls r0, r2, #5
	orrs r0, r2
	lsls r1, r2, #0xa
	orrs r0, r1
	strh r0, [r5]
	adds r4, #2
	adds r5, #2
	subs r6, #1
	cmp r6, #0
	bge _0822D89C
_0822D8D0:
	adds r3, r7, #0
	cmp r3, #0xf
	ble _0822D844
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0822D8E4: .4byte 0x000002FA
