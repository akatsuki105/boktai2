	push {r4, lr}
	adds r4, r0, #0
	ldr r1, _082292F0 @ =0x00000F16
	adds r0, r4, r1
	ldrb r1, [r0]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	bne _082292F4
	movs r0, #1
	b _08229326
	.align 2, 0
_082292F0: .4byte 0x00000F16
_082292F4:
	adds r0, r4, #0
	bl FUN_082292ac
	movs r2, #0xf5
	lsls r2, r2, #4
	adds r1, r4, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _0822930C
	adds r0, r4, #0
	bl _call_via_r1
_0822930C:
	ldr r2, _0822932C @ =0x00000F54
	adds r1, r4, r2
	ldr r1, [r1]
	cmp r1, #0
	beq _0822931C
	adds r0, r4, #0
	bl _call_via_r1
_0822931C:
	ldr r1, _08229330 @ =0x00000F5C
	adds r2, r4, r1
	ldr r1, [r2]
	adds r1, #1
	str r1, [r2]
_08229326:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_0822932C: .4byte 0x00000F54
_08229330: .4byte 0x00000F5C
