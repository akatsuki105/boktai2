	push {r4, r5, r6, lr}
	adds r5, r0, #0
	ldr r0, _08099074 @ =0x000009F8
	adds r1, r5, r0
	movs r0, #0
	strb r0, [r1]
	movs r3, #0
	movs r1, #0
	ldr r0, _08099078 @ =0x00004008
	adds r2, r5, r0
_0809901C:
	adds r0, r2, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _08099026
	movs r3, #1
_08099026:
	adds r1, #1
	cmp r1, #3
	ble _0809901C
	cmp r3, #0
	bne _08099090
	ldr r0, _0809907C @ =0x030044E0
	ldrh r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _08099090
	ldr r1, _08099074 @ =0x000009F8
	adds r0, r5, r1
	movs r2, #1
	strb r2, [r0]
	ldr r3, _08099080 @ =0x0000282C
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _08099084 @ =0x0000288C
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r3, _08099088 @ =0x0000144C
	adds r1, r5, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _0809908C @ =0x000020AC
	adds r1, r5, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_0808c700
	b _08099288
	.align 2, 0
_08099074: .4byte 0x000009F8
_08099078: .4byte 0x00004008
_0809907C: .4byte 0x030044E0
_08099080: .4byte 0x0000282C
_08099084: .4byte 0x0000288C
_08099088: .4byte 0x0000144C
_0809908C: .4byte 0x000020AC
_08099090:
	ldr r1, _080990CC @ =0x000009F8
	adds r4, r5, r1
	strb r3, [r4]
	adds r0, r5, #0
	bl FUN_0808b6a4
	adds r1, r0, #0
	movs r0, #0x40
	ands r0, r1
	cmp r0, #0
	beq _080990D8
	ldr r2, _080990D0 @ =0x00004002
	adds r4, r5, r2
	ldrb r0, [r4]
	adds r0, #3
	movs r1, #3
	ands r0, r1
	strb r0, [r4]
	adds r0, r5, #0
	bl FUN_08098e48
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldrb r0, [r4]
	adds r0, #0x14
	ldr r3, _080990D4 @ =0x00004003
	adds r1, r5, r3
	strb r0, [r1]
	b _0809921A
	.align 2, 0
_080990CC: .4byte 0x000009F8
_080990D0: .4byte 0x00004002
_080990D4: .4byte 0x00004003
_080990D8:
	movs r0, #0x80
	ands r0, r1
	cmp r0, #0
	beq _08099110
	ldr r0, _08099108 @ =0x00004002
	adds r4, r5, r0
	ldrb r0, [r4]
	adds r0, #1
	movs r1, #3
	ands r0, r1
	strb r0, [r4]
	adds r0, r5, #0
	bl FUN_08098e48
	movs r0, #0xdc
	bl PlaySound_082406e0
	ldrb r0, [r4]
	adds r0, #0x14
	ldr r2, _0809910C @ =0x00004003
	adds r1, r5, r2
	strb r0, [r1]
	b _0809921A
	.align 2, 0
_08099108: .4byte 0x00004002
_0809910C: .4byte 0x00004003
_08099110:
	movs r0, #0x20
	ands r0, r1
	cmp r0, #0
	beq _08099144
	ldr r3, _0809913C @ =0x00004002
	adds r1, r5, r3
	ldr r2, _08099140 @ =0x00004008
	adds r0, r5, r2
	ldrb r1, [r1]
	adds r1, r0, r1
	ldrb r0, [r1]
	cmp r0, #0
	beq _0809921A
	subs r0, #1
	strb r0, [r1]
	subs r3, #2
	adds r1, r5, r3
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	b _08099196
	.align 2, 0
_0809913C: .4byte 0x00004002
_08099140: .4byte 0x00004008
_08099144:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _080991B8
	movs r0, #0x80
	lsls r0, r0, #7
	adds r4, r5, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _0809921A
	movs r1, #0x9e
	lsls r1, r1, #4
	adds r0, r5, r1
	ldr r0, [r0]
	ldr r2, _080991AC @ =0x00004002
	adds r1, r5, r2
	ldrb r2, [r1]
	lsls r1, r2, #1
	movs r3, #0xd7
	lsls r3, r3, #2
	adds r0, r0, r3
	adds r0, r0, r1
	ldrh r1, [r0]
	ldr r3, _080991B0 @ =0x00004008
	adds r0, r5, r3
	adds r6, r0, r2
	ldrb r3, [r6]
	adds r1, r1, r3
	cmp r1, #0x62
	bgt _0809921A
	ldr r1, _080991B4 @ =0x00004004
	adds r0, r5, r1
	adds r0, r0, r2
	ldrb r0, [r0]
	cmp r0, #0x62
	bhi _0809921A
	adds r0, r3, #1
	strb r0, [r6]
	ldrh r0, [r4]
	subs r0, #1
	strh r0, [r4]
_08099196:
	adds r0, r5, #0
	bl FUN_08098af4
	adds r0, r5, #0
	bl FUN_08098d98
	movs r0, #0xcd
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0809921A
	.align 2, 0
_080991AC: .4byte 0x00004002
_080991B0: .4byte 0x00004008
_080991B4: .4byte 0x00004004
_080991B8:
	ldr r2, _080991EC @ =0x030044E0
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _080991F8
	ldrb r0, [r4]
	cmp r0, #0
	beq _080991F8
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r2, _080991F0 @ =0x00004003
	adds r0, r5, r2
	movs r1, #0x18
	strb r1, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0808b6fc
	ldr r1, _080991F4 @ =FUN_080992c0
	adds r0, r5, #0
	movs r2, #1
	bl EntityCC28_SetState
	b _0809921A
	.align 2, 0
_080991EC: .4byte 0x030044E0
_080991F0: .4byte 0x00004003
_080991F4: .4byte FUN_080992c0
_080991F8:
	ldrh r1, [r2, #2]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0809921A
	movs r0, #0xde
	bl PlaySound_082406e0
	adds r0, r5, #0
	bl FUN_08098edc
	adds r0, r5, #0
	bl FUN_08098af4
	adds r0, r5, #0
	bl FUN_08098d98
_0809921A:
	ldr r3, _08099244 @ =0x0000282C
	adds r1, r5, r3
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r1, _08099248 @ =0x000009F8
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _0809924C
	adds r3, #0x60
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	adds r0, r5, #0
	bl FUN_0808c700
	b _08099264
	.align 2, 0
_08099244: .4byte 0x0000282C
_08099248: .4byte 0x000009F8
_0809924C:
	ldr r0, _080992AC @ =0x0000288C
	adds r2, r5, r0
	ldr r0, [r2]
	movs r1, #1
	orrs r0, r1
	str r0, [r2]
	movs r2, #1
	rsbs r2, r2, #0
	adds r0, r5, #0
	movs r1, #0
	bl FUN_0808c658
_08099264:
	ldr r2, _080992B0 @ =0x000020AC
	adds r1, r5, r2
	ldr r0, [r1]
	movs r2, #2
	rsbs r2, r2, #0
	ands r0, r2
	str r0, [r1]
	ldr r3, _080992B4 @ =0x0000144C
	adds r1, r5, r3
	ldr r0, [r1]
	ands r0, r2
	str r0, [r1]
	ldr r1, _080992B8 @ =0x00001444
	adds r0, r5, r1
	adds r1, r5, #0
	adds r1, #0x60
	bl MainSprite_AdvanceAnim
_08099288:
	adds r0, r5, #0
	bl FUN_08098c24
	ldr r2, _080992BC @ =0x00004003
	adds r4, r5, r2
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r0, #0
	blt _080992A6
	adds r1, r0, #0
	adds r0, r5, #0
	bl EntityCC28_ShowLineInstant
	movs r0, #0xff
	strb r0, [r4]
_080992A6:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080992AC: .4byte 0x0000288C
_080992B0: .4byte 0x000020AC
_080992B4: .4byte 0x0000144C
_080992B8: .4byte 0x00001444
_080992BC: .4byte 0x00004003
