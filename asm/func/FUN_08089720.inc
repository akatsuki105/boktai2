	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _080897B4 @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0x10
	beq _08089736
	adds r0, r4, #0
	movs r1, #0x10
	bl Coffin_SetState
_08089736:
	ldr r2, _080897B8 @ =0x0000032A
	adds r1, r4, r2
	movs r0, #1
	strh r0, [r1]
	movs r3, #0xe2
	lsls r3, r3, #2
	adds r2, r4, r3
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r4, #0x48]
	str r1, [r4, #0x4c]
	adds r0, r4, #0
	adds r0, #0x48
	movs r3, #0
	ldrsh r1, [r0, r3]
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _08089760
	rsbs r1, r1, #0
_08089760:
	cmp r1, #2
	bgt _08089782
	adds r0, r4, #0
	adds r0, #0x4c
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r3, #0xe3
	lsls r3, r3, #2
	adds r0, r4, r3
	movs r2, #0
	ldrsh r0, [r0, r2]
	subs r1, r1, r0
	cmp r1, #0
	bge _0808977E
	rsbs r1, r1, #0
_0808977E:
	cmp r1, #2
	ble _0808978A
_08089782:
	ldr r3, _080897BC @ =0x0000033A
	adds r1, r4, r3
	movs r0, #1
	strb r0, [r1]
_0808978A:
	ldr r1, _080897C0 @ =0x0000038E
	adds r0, r4, r1
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #2
	adds r0, r4, r2
	strb r1, [r0]
	ldrb r0, [r4, #0x1a]
	cmp r0, #5
	bne _080897C4
	ldr r3, _080897BC @ =0x0000033A
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _080897C4
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _080897CC
	.align 2, 0
_080897B4: .4byte 0x000001F5
_080897B8: .4byte 0x0000032A
_080897BC: .4byte 0x0000033A
_080897C0: .4byte 0x0000038E
_080897C4:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
_080897CC:
	ldr r0, _080897F0 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08089820
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _080897F4
	adds r0, r4, #0
	bl FUN_08087a5c
	b _08089820
	.align 2, 0
_080897F0: .4byte 0x030047A4
_080897F4:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _08089814
	ldr r3, _08089810 @ =0x0000032A
	adds r0, r4, r3
	strh r1, [r0]
	adds r0, r4, #0
	bl FUN_080856f4
	b _08089820
	.align 2, 0
_08089810: .4byte 0x0000032A
_08089814:
	adds r0, r4, #0
	bl FUN_080895d0
	adds r0, r4, #0
	bl FUN_080880fc
_08089820:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
