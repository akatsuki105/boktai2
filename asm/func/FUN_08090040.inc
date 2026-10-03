	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r0, _08090084 @ =0x00002CAC
	adds r2, r3, r0
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r5, _08090088 @ =0x00002D0C
	adds r4, r3, r5
	ldr r0, [r4]
	ands r0, r1
	str r0, [r4]
	ldr r6, _0809008C @ =0x00004040
	adds r1, r3, r6
	ldr r7, _08090090 @ =0x00004044
	adds r0, r3, r7
	movs r6, #0
	ldrsh r5, [r1, r6]
	ldrh r6, [r0]
	movs r7, #0
	ldrsh r0, [r0, r7]
	cmp r5, r0
	bgt _08090094
	strh r6, [r1]
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	b _080900AC
	.align 2, 0
_08090084: .4byte 0x00002CAC
_08090088: .4byte 0x00002D0C
_0809008C: .4byte 0x00004040
_08090090: .4byte 0x00004044
_08090094:
	ldr r2, _080900E8 @ =0x00004048
	adds r0, r3, r2
	ldrh r2, [r0]
	movs r6, #0
	ldrsh r0, [r0, r6]
	cmp r5, r0
	blt _080900AC
	strh r2, [r1]
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
_080900AC:
	ldr r7, _080900EC @ =0x00002D6C
	adds r4, r3, r7
	ldr r0, [r4]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r4]
	ldr r0, _080900F0 @ =0x00002DCC
	adds r5, r3, r0
	ldr r2, [r5]
	ands r2, r1
	str r2, [r5]
	ldr r1, _080900F4 @ =0x00004042
	adds r6, r3, r1
	ldr r7, _080900F8 @ =0x00004046
	adds r7, r7, r3
	movs r1, #0
	ldrsh r0, [r6, r1]
	mov r8, r0
	movs r1, #0
	ldrsh r0, [r7, r1]
	cmp r8, r0
	bgt _080900FC
	ldr r0, [r4]
	movs r1, #1
	orrs r0, r1
	str r0, [r4]
	ldrh r0, [r7]
	b _08090110
	.align 2, 0
_080900E8: .4byte 0x00004048
_080900EC: .4byte 0x00002D6C
_080900F0: .4byte 0x00002DCC
_080900F4: .4byte 0x00004042
_080900F8: .4byte 0x00004046
_080900FC:
	ldr r7, _0809011C @ =0x0000404A
	adds r1, r3, r7
	movs r3, #0
	ldrsh r0, [r1, r3]
	cmp r8, r0
	blt _08090112
	movs r0, #1
	orrs r2, r0
	str r2, [r5]
	ldrh r0, [r1]
_08090110:
	strh r0, [r6]
_08090112:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809011C: .4byte 0x0000404A
