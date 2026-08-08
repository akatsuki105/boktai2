	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov sb, r0
	str r1, [sp]
	ldr r1, _08234A64 @ =0x030046B0
	ldr r0, [r1]
	ldr r2, _08234A68 @ =0x030046A4
	mov r8, r2
	cmp r0, #0
	bne _082349D8
	movs r0, #1
	str r0, [r1]
_082349D8:
	ldr r0, [r1]
	mov r3, sb
	str r0, [r3]
	adds r0, #1
	str r0, [r1]
	movs r4, #0
	mov r6, r8
	ldr r1, [r6]
	ldrh r5, [r1]
	cmp r5, #0
	ble _08234A26
	subs r2, r5, #1
	movs r0, #0x2c
	muls r0, r2, r0
	adds r0, r1, r0
	movs r7, #0x8b
	lsls r7, r7, #2
	adds r0, r0, r7
	ldrh r1, [r3, #8]
	adds r3, r1, #0
	ldrh r0, [r0]
	cmp r3, r0
	beq _08234A70
_08234A06:
	adds r5, r2, #0
	cmp r5, #0
	ble _08234A26
	mov r0, r8
	ldr r1, [r0]
	subs r2, r5, #1
	movs r0, #0x2c
	muls r0, r2, r0
	adds r1, r1, r0
	movs r6, #0x8b
	lsls r6, r6, #2
	adds r1, r1, r6
	ldrh r1, [r1]
	cmp r3, r1
	bne _08234A06
	movs r4, #1
_08234A26:
	cmp r4, #0
	bne _08234A70
	mov r7, r8
	ldr r1, [r7]
	ldrh r2, [r1]
	movs r0, #0x2c
	muls r0, r2, r0
	adds r1, r1, r0
	movs r0, #0x89
	lsls r0, r0, #2
	adds r1, r1, r0
	mov r0, sb
	ldm r0!, {r2, r3, r4}
	stm r1!, {r2, r3, r4}
	ldm r0!, {r2, r6, r7}
	stm r1!, {r2, r6, r7}
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r2, r7}
	stm r1!, {r2, r7}
	mov r3, r8
	ldr r0, [r3]
	ldrh r1, [r0]
	lsls r1, r1, #2
	ldr r4, _08234A6C @ =0x00000D24
	adds r0, r0, r4
	adds r0, r0, r1
	ldr r6, [sp]
	str r6, [r0]
	b _08234AFC
	.align 2, 0
_08234A64: .4byte 0x030046B0
_08234A68: .4byte 0x030046A4
_08234A6C: .4byte 0x00000D24
_08234A70:
	mov r7, r8
	ldr r0, [r7]
	ldrh r4, [r0]
	lsls r0, r5, #2
	str r0, [sp, #4]
	cmp r4, r5
	ble _08234ACA
	mov ip, r8
	ldr r1, _08234B18 @ =0x00000D24
	mov sl, r1
_08234A84:
	mov r2, ip
	ldr r1, [r2]
	movs r3, #0x2c
	adds r0, r4, #0
	muls r0, r3, r0
	adds r0, r1, r0
	subs r3, r4, #1
	movs r6, #0x2c
	adds r2, r3, #0
	muls r2, r6, r2
	adds r1, r1, r2
	movs r7, #0x89
	lsls r7, r7, #2
	adds r0, r0, r7
	adds r1, r1, r7
	ldm r1!, {r2, r6, r7}
	stm r0!, {r2, r6, r7}
	ldm r1!, {r2, r6, r7}
	stm r0!, {r2, r6, r7}
	ldm r1!, {r2, r6, r7}
	stm r0!, {r2, r6, r7}
	ldm r1!, {r2, r6}
	stm r0!, {r2, r6}
	mov r7, ip
	ldr r1, [r7]
	lsls r2, r4, #2
	add r1, sl
	adds r2, r1, r2
	lsls r0, r3, #2
	adds r1, r1, r0
	ldr r0, [r1]
	str r0, [r2]
	adds r4, r3, #0
	cmp r4, r5
	bgt _08234A84
_08234ACA:
	mov r0, r8
	ldr r1, [r0]
	movs r0, #0x2c
	muls r0, r5, r0
	adds r1, r1, r0
	movs r2, #0x89
	lsls r2, r2, #2
	adds r1, r1, r2
	mov r0, sb
	ldm r0!, {r3, r4, r6}
	stm r1!, {r3, r4, r6}
	ldm r0!, {r2, r3, r7}
	stm r1!, {r2, r3, r7}
	ldm r0!, {r4, r6, r7}
	stm r1!, {r4, r6, r7}
	ldm r0!, {r2, r3}
	stm r1!, {r2, r3}
	mov r4, r8
	ldr r0, [r4]
	ldr r6, _08234B18 @ =0x00000D24
	adds r0, r0, r6
	ldr r7, [sp, #4]
	adds r0, r0, r7
	ldr r1, [sp]
	str r1, [r0]
_08234AFC:
	mov r2, r8
	ldr r1, [r2]
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08234B18: .4byte 0x00000D24
