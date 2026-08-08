	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x1c]
	cmp r0, #1
	bne _0807AA7E
	movs r0, #0xda
	lsls r0, r0, #2
	adds r2, r2, r0
	ldrh r0, [r2]
	cmp r0, r1
	bge _0807AA7A
	movs r0, #0
	b _0807AA7C
_0807AA7A:
	subs r0, r0, r1
_0807AA7C:
	strh r0, [r2]
_0807AA7E:
	pop {r0}
	bx r0
	.align 2, 0
