	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r6, r0, #0
	movs r1, #0xce
	lsls r1, r1, #1
	ldrh r0, [r6, #0x24]
	cmp r0, r1
	beq _0809E7B6
	strh r1, [r6, #0x24]
	movs r2, #0
	adds r0, r6, #0
	adds r0, #0x26
	mov r8, r0
	ldrb r0, [r0]
	cmp r2, r0
	bge _0809E7B6
	movs r1, #0xa8
	mov sb, r1
_0809E784:
	mov r1, sb
	muls r1, r2, r1
	adds r0, r6, r1
	adds r0, #0xc9
	ldrb r0, [r0]
	adds r7, r2, #1
	cmp r0, #0
	beq _0809E7AC
	adds r0, r1, #0
	adds r0, #0x8c
	adds r4, r6, r0
	movs r5, #1
_0809E79C:
	ldrh r1, [r6, #0x24]
	adds r0, r4, #0
	bl Video_SetAuxSpritePltt
	adds r4, #0x1c
	subs r5, #1
	cmp r5, #0
	bge _0809E79C
_0809E7AC:
	adds r2, r7, #0
	mov r0, r8
	ldrb r0, [r0]
	cmp r2, r0
	blt _0809E784
_0809E7B6:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
