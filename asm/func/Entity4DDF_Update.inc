	push {r4, r5, lr}
	sub sp, #0x18
	adds r3, r0, #0
	mov r1, sp
	ldr r0, _08211DE4 @ =0x08252738
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	ldm r0!, {r2, r4, r5}
	stm r1!, {r2, r4, r5}
	movs r1, #0xc8
	lsls r1, r1, #2
	adds r0, r3, r1
	movs r2, #0
	ldrsh r1, [r0, r2]
	movs r4, #0xc7
	lsls r4, r4, #2
	adds r0, r3, r4
	ldr r0, [r0]
	cmp r1, r0
	bgt _08211DDA
	lsls r0, r1, #1
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r0, #0x18
	adds r1, r3, r0
	movs r5, #0xc9
	lsls r5, r5, #2
	adds r0, r3, r5
	ldrb r0, [r0]
	lsls r0, r0, #2
	add r0, sp
	ldr r2, [r0]
	cmp r2, #0
	beq _08211DDA
	adds r0, r3, #0
	bl _call_via_r2
_08211DDA:
	movs r0, #0
	add sp, #0x18
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0
_08211DE4: .4byte 0x08252738
