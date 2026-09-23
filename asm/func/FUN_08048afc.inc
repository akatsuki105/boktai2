	push {lr}
	ldr r2, _08048B10 @ =0x085AB45C
	ldrh r1, [r2]
	cmp r1, #0
	beq _08048B1C
	ldrb r0, [r0, #1]
_08048B08:
	cmp r1, r0
	bne _08048B14
	ldrh r0, [r2, #2]
	b _08048B1E
	.align 2, 0
_08048B10: .4byte 0x085AB45C
_08048B14:
	adds r2, #4
	ldrh r1, [r2]
	cmp r1, #0
	bne _08048B08
_08048B1C:
	ldr r0, _08048B24 @ =0x0000FFFF
_08048B1E:
	pop {r1}
	bx r1
	.align 2, 0
_08048B24: .4byte 0x0000FFFF
