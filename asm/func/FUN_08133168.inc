	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08133180 @ =0x0000046D
	adds r1, r4, r0
	ldrb r0, [r1]
	cmp r0, #0
	beq _08133184
	movs r0, #0
	strb r0, [r1]
	movs r0, #1
	b _08133186
	.align 2, 0
_08133180: .4byte 0x0000046D
_08133184:
	movs r0, #0
_08133186:
	cmp r0, #0
	beq _08133192
	adds r0, r4, #0
	movs r1, #0xb
	bl Enemy_PlayAnim
_08133192:
	ldr r1, _081331AC @ =0x0000046E
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #0
	beq _081331A4
	ldr r0, _081331B0 @ =0x0000046B
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
_081331A4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081331AC: .4byte 0x0000046E
_081331B0: .4byte 0x0000046B
