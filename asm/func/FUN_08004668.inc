	push {r4, lr}
	ldr r1, [r0, #0x70]
	movs r2, #0
	ldrh r0, [r0, #0x18]
	cmp r2, r0
	bge _0800468C
	movs r4, #0xce
	lsls r4, r4, #1
	adds r3, r0, #0
_0800467A:
	ldrb r0, [r1, #0x1e]
	cmp r0, #0
	bne _08004684
	adds r0, r1, #0
	b _0800468E
_08004684:
	adds r1, r1, r4
	adds r2, #1
	cmp r2, r3
	blt _0800467A
_0800468C:
	movs r0, #0
_0800468E:
	pop {r4}
	pop {r1}
	bx r1
