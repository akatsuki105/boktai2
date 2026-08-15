	push {lr}
	adds r2, r0, #0
	ldr r1, _08060E60 @ =0x0000038E
	adds r0, r2, r1
	ldrb r0, [r0]
	ldr r1, _08060E64 @ =0x030046A0
	ldr r1, [r1]
	lsls r0, r0, #2
	adds r0, r0, r1
	movs r3, #0xb2
	lsls r3, r3, #2
	adds r0, r0, r3
	ldr r0, [r0]
	cmp r0, #0
	bgt _08060E5C
	movs r1, #0x80
	lsls r1, r1, #3
	movs r3, #0xde
	lsls r3, r3, #2
	adds r0, r2, r3
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08060E5C
	bl FUN_0823e1b0
	adds r1, r0, #0
	subs r0, r1, #4
	cmp r0, #1
	bls _08060E5C
	cmp r1, #0
	bne _08060E68
_08060E5C:
	movs r0, #1
	b _08060E6A
	.align 2, 0
_08060E60: .4byte 0x0000038E
_08060E64: .4byte 0x030046A0
_08060E68:
	movs r0, #0
_08060E6A:
	pop {r1}
	bx r1
	.align 2, 0
