	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	ldr r0, _08180560 @ =0x0000046D
	adds r1, r6, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08180564
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08180566
	.align 2, 0
_08180560: .4byte 0x0000046D
_08180564:
	movs r0, #0
_08180566:
	cmp r0, #0
	beq _0818058E
	ldr r1, _081805C0 @ =0x000001DD
	adds r0, r6, r1
	ldrb r0, [r0]
	strb r0, [r6, #5]
	adds r0, r6, #0
	movs r1, #3
	bl Enemy_PlayAnim
	movs r0, #0x20
	movs r4, #0xc0
	lsls r4, r4, #1
	adds r2, r6, r4
	ldrh r1, [r2]
	orrs r0, r1
	strh r0, [r2]
	ldr r0, _081805C4 @ =0x000002D5
	bl PlaySound_082406e0
_0818058E:
	movs r2, #0x80
	lsls r2, r2, #6
	movs r5, #0xbc
	lsls r5, r5, #1
	adds r1, r6, r5
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r2, #0x83
	lsls r2, r2, #2
	adds r0, r6, r2
	movs r4, #0
	ldrsh r3, [r0, r4]
	adds r5, #0x9c
	adds r2, r6, r5
	movs r4, #0
	ldrsh r0, [r2, r4]
	subs r0, r3, r0
	adds r7, r1, #0
	adds r4, r2, #0
	cmp r0, #0
	blt _081805C8
	asrs r0, r0, #2
	b _081805CE
	.align 2, 0
_081805C0: .4byte 0x000001DD
_081805C4: .4byte 0x000002D5
_081805C8:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081805CE:
	adds r3, r0, #0
	movs r5, #0x84
	lsls r5, r5, #2
	adds r0, r6, r5
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r5, #8
	adds r1, r6, r5
	movs r5, #0
	ldrsh r0, [r1, r5]
	subs r0, r2, r0
	cmp r0, #0
	blt _081805EC
	asrs r0, r0, #2
	b _081805F2
_081805EC:
	rsbs r0, r0, #0
	asrs r0, r0, #2
	rsbs r0, r0, #0
_081805F2:
	adds r2, r0, #0
	cmp r3, #0xc8
	ble _081805FC
	movs r3, #0xc8
	b _08180606
_081805FC:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r3, r0
	bge _08180606
	adds r3, r0, #0
_08180606:
	cmp r2, #0xc8
	ble _0818060E
	movs r2, #0xc8
	b _08180618
_0818060E:
	movs r0, #0xc8
	rsbs r0, r0, #0
	cmp r2, r0
	bge _08180618
	adds r2, r0, #0
_08180618:
	ldrh r0, [r6, #0x10]
	adds r0, r0, r3
	strh r0, [r6, #0x10]
	ldrh r0, [r6, #0x14]
	adds r0, r0, r2
	strh r0, [r6, #0x14]
	ldrh r0, [r4]
	adds r0, r0, r3
	strh r0, [r4]
	ldrh r0, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	cmp r3, #0
	bne _0818063C
	cmp r2, #0
	bne _0818063C
	movs r0, #1
	b _0818063E
_0818063C:
	movs r0, #0
_0818063E:
	cmp r0, #0
	beq _08180688
	ldr r1, _08180690 @ =0x0000046B
	adds r0, r6, r1
	movs r5, #0
	movs r4, #1
	strb r4, [r0]
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r3, r6, r2
	movs r0, #0x21
	rsbs r0, r0, #0
	ldrh r1, [r3]
	ands r0, r1
	movs r2, #0
	strh r0, [r3]
	movs r1, #0x81
	rsbs r1, r1, #0
	ldr r0, [r7]
	ands r0, r1
	str r0, [r7]
	movs r1, #0x8d
	lsls r1, r1, #3
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	adds r1, #1
	adds r0, r6, r1
	strb r2, [r0]
	ldr r2, _08180694 @ =0x00000484
	adds r0, r6, r2
	str r5, [r0]
	ldr r5, _08180698 @ =0x0000046C
	adds r0, r6, r5
	strb r4, [r0]
_08180688:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08180690: .4byte 0x0000046B
_08180694: .4byte 0x00000484
_08180698: .4byte 0x0000046C
