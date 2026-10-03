	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _08049D04 @ =0x00000179
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049CBC
	adds r0, r4, #0
	bl FUN_08049c3c
	movs r0, #0
	strb r0, [r5]
_08049CBC:
	movs r1, #0xbd
	lsls r1, r1, #1
	adds r5, r4, r1
	ldrb r0, [r5]
	cmp r0, #0
	beq _08049CD2
	adds r0, r4, #0
	bl FUN_08049c78
	movs r0, #0
	strb r0, [r5]
_08049CD2:
	movs r2, #0xbc
	lsls r2, r2, #1
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _08049D26
	adds r5, r4, #0
	adds r5, #0x18
	adds r0, r5, #0
	bl TextRenderer_ClearPending
	adds r0, r4, #0
	bl FUN_0804996c
	ldr r1, _08049D08 @ =0x0000017B
	adds r0, r4, r1
	ldrb r1, [r0]
	cmp r1, #0
	beq _08049D10
	ldr r0, _08049D0C @ =0x03002CE8
	movs r2, #0xc2
	lsls r2, r2, #1
	adds r1, r4, r2
	ldr r1, [r1]
	b _08049D12
	.align 2, 0
_08049D04: .4byte 0x00000179
_08049D08: .4byte 0x0000017B
_08049D0C: .4byte 0x03002CE8
_08049D10:
	ldr r0, _08049D30 @ =0x03002CE8
_08049D12:
	str r1, [r0]
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r1, r4, r0
	ldr r0, [r1]
	adds r0, #1
	str r0, [r1]
	adds r0, r5, #0
	bl TextRenderer_RunPending
_08049D26:
	movs r0, #0
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08049D30: .4byte 0x03002CE8
