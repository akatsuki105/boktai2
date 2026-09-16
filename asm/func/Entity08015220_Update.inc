	push {r4, r5, r6, lr}
	adds r5, r0, #0
	adds r4, r5, #0
	adds r4, #0x20
	movs r6, #3
_0801515A:
	ldrb r0, [r4]
	cmp r0, #0
	beq _08015168
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_08015074
_08015168:
	movs r0, #0xbc
	lsls r0, r0, #1
	adds r4, r4, r0
	subs r6, #1
	cmp r6, #0
	bge _0801515A
	ldr r0, [r5, #0x18]
	adds r0, #1
	str r0, [r5, #0x18]
	movs r0, #0
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
