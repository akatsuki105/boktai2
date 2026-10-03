	push {lr}
	adds r1, r0, #0
	ldr r0, _08044044 @ =0x03002B50
	str r1, [r0]
	movs r0, #0
	str r0, [r1, #0x18]
	str r0, [r1, #0x1c]
	str r0, [r1, #0x28]
	str r0, [r1, #0x2c]
	str r0, [r1, #0x30]
	ldr r0, _08044048 @ =0x03002BE0
	ldr r2, [r0]
	movs r3, #0x87
	lsls r3, r3, #3
	adds r0, r1, r3
	str r2, [r0]
	cmp r2, #0
	beq _08044050
	ldr r0, _0804404C @ =0x00000434
	adds r1, r1, r0
	adds r0, r2, #0
	adds r0, #0x2c
	str r0, [r1]
	b _08044056
	.align 2, 0
_08044044: .4byte 0x03002B50
_08044048: .4byte 0x03002BE0
_0804404C: .4byte 0x00000434
_08044050:
	ldr r3, _0804405C @ =0x00000434
	adds r0, r1, r3
	str r2, [r0]
_08044056:
	movs r0, #0
	pop {r1}
	bx r1
	.align 2, 0
_0804405C: .4byte 0x00000434
