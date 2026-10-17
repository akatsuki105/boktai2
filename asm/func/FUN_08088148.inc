	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _080881CC @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #1
	beq _0808815E
	adds r0, r4, #0
	movs r1, #1
	bl Coffin_SetState
_0808815E:
	movs r2, #0xed
	lsls r2, r2, #2
	adds r3, r4, r2
	ldrh r0, [r3]
	cmp r0, #0
	beq _080881AE
	ldr r5, _080881D0 @ =0x000003A2
	adds r0, r4, r5
	ldrh r0, [r0]
	cmp r0, #0
	beq _080881AE
	adds r0, r4, #0
	adds r0, #0x48
	movs r1, #0
	ldrsh r2, [r0, r1]
	adds r5, #6
	adds r0, r4, r5
	movs r1, #0
	ldrsh r0, [r0, r1]
	subs r1, r2, r0
	cmp r1, #0
	bge _0808818C
	rsbs r1, r1, #0
_0808818C:
	movs r5, #0xeb
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r5, #0
	ldrsh r0, [r0, r5]
	subs r0, r2, r0
	cmp r0, #0
	bge _0808819E
	rsbs r0, r0, #0
_0808819E:
	movs r2, #0x80
	lsls r2, r2, #1
	cmp r1, r2
	bgt _080881AA
	cmp r0, r2
	ble _080881AE
_080881AA:
	movs r0, #0
	strh r0, [r3]
_080881AE:
	ldr r0, _080881D4 @ =0x0000032A
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	movs r1, #0xe8
	lsls r1, r1, #2
	adds r0, r4, r1
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	blt _080881D8
	adds r0, r4, #0
	bl FUN_08087f7c
	b _08088230
	.align 2, 0
_080881CC: .4byte 0x000001F5
_080881D0: .4byte 0x000003A2
_080881D4: .4byte 0x0000032A
_080881D8:
	adds r2, r4, #0
	adds r2, #0x48
	movs r3, #0
	ldrsh r1, [r2, r3]
	movs r5, #0xe2
	lsls r5, r5, #2
	adds r0, r4, r5
	movs r3, #0
	ldrsh r0, [r0, r3]
	subs r1, r1, r0
	cmp r1, #0
	bge _080881F2
	rsbs r1, r1, #0
_080881F2:
	adds r3, r4, #0
	adds r3, #0x4c
	cmp r1, #2
	bgt _08088214
	movs r5, #0
	ldrsh r0, [r3, r5]
	movs r5, #0xe3
	lsls r5, r5, #2
	adds r1, r4, r5
	movs r5, #0
	ldrsh r1, [r1, r5]
	subs r0, r0, r1
	cmp r0, #0
	bge _08088210
	rsbs r0, r0, #0
_08088210:
	cmp r0, #2
	ble _0808821C
_08088214:
	ldr r0, _08088258 @ =0x0000033A
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_0808821C:
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r0, [r0]
	strh r0, [r2]
	movs r2, #0xe3
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	strh r0, [r3]
_08088230:
	ldr r3, _0808825C @ =0x0000038E
	adds r0, r4, r3
	ldrh r1, [r0]
	movs r5, #0x80
	lsls r5, r5, #2
	adds r0, r4, r5
	strb r1, [r0]
	ldrb r0, [r4, #0x1a]
	cmp r0, #5
	bne _08088260
	ldr r1, _08088258 @ =0x0000033A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08088260
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _08088268
	.align 2, 0
_08088258: .4byte 0x0000033A
_0808825C: .4byte 0x0000038E
_08088260:
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
_08088268:
	ldr r0, _0808828C @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080882DE
	movs r2, #0xe5
	lsls r2, r2, #2
	adds r3, r4, r2
	ldrh r0, [r3]
	cmp r0, #0
	beq _08088290
	adds r0, r4, #0
	bl FUN_08087a5c
	b _080882DE
	.align 2, 0
_0808828C: .4byte 0x030047A4
_08088290:
	movs r5, #0xc9
	lsls r5, r5, #2
	adds r0, r4, r5
	ldrh r2, [r0]
	cmp r2, #0
	beq _080882A4
	adds r0, r4, #0
	bl FUN_080856f4
	b _080882DE
_080882A4:
	ldr r1, _080882CC @ =0x0000040A
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _080882D8
	ldr r5, _080882D0 @ =0x00000392
	adds r0, r4, r5
	ldrh r1, [r0]
	subs r5, #2
	adds r0, r4, r5
	strh r1, [r0]
	ldr r1, _080882D4 @ =0x000003A6
	adds r0, r4, r1
	ldrh r1, [r0]
	adds r5, #0x14
	adds r0, r4, r5
	strh r1, [r0]
	strh r2, [r3]
	b _080882DE
	.align 2, 0
_080882CC: .4byte 0x0000040A
_080882D0: .4byte 0x00000392
_080882D4: .4byte 0x000003A6
_080882D8:
	adds r0, r4, #0
	bl FUN_080880fc
_080882DE:
	pop {r4, r5}
	pop {r0}
	bx r0
