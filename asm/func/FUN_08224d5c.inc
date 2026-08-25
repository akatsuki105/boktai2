	push {r4, lr}
	ldr r0, _08224D88 @ =0x03000248
	ldr r4, [r0]
	cmp r4, #0
	bne _08224D74
	ldr r0, _08224D8C @ =0x0000BB34
	movs r1, #0
	bl Entity8AAB_Create
	adds r4, r0, #0
	cmp r4, #0
	beq _08224D82
_08224D74:
	movs r0, #0x70
	movs r1, #0
	bl Script_GetKeywordValue
	ldr r2, _08224D90 @ =0x00000DA3
	adds r1, r4, r2
	strb r0, [r1]
_08224D82:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08224D88: .4byte 0x03000248
_08224D8C: .4byte 0x0000BB34
_08224D90: .4byte 0x00000DA3
