	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r1, _0808959C @ =0x000001F5
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0xf
	beq _0808955E
	adds r0, r4, #0
	movs r1, #0xf
	bl Coffin_SetState
_0808955E:
	adds r2, r4, #0
	adds r2, #0xe2
	ldrh r1, [r2]
	ldr r0, _080895A0 @ =0x0000FFFB
	ands r0, r1
	strh r0, [r2]
	ldr r2, _080895A4 @ =0x0000032A
	adds r5, r4, r2
	movs r0, #1
	strh r0, [r5]
	adds r0, r4, #0
	movs r1, #0
	bl FUN_08086024
	ldr r0, _080895A8 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #2
	ands r0, r1
	cmp r0, #0
	bne _080895C8
	movs r1, #0xe5
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrh r1, [r0]
	cmp r1, #0
	beq _080895AC
	adds r0, r4, #0
	bl FUN_08087a5c
	b _080895C8
	.align 2, 0
_0808959C: .4byte 0x000001F5
_080895A0: .4byte 0x0000FFFB
_080895A4: .4byte 0x0000032A
_080895A8: .4byte 0x030047A4
_080895AC:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _080895C2
	strh r1, [r5]
	adds r0, r4, #0
	bl FUN_080856f4
	b _080895C8
_080895C2:
	adds r0, r4, #0
	bl FUN_08089410
_080895C8:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
