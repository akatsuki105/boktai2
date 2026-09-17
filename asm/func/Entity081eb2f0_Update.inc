	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	movs r1, #0x92
	lsls r1, r1, #4
	adds r0, r7, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EB25C
	movs r6, #0
	movs r2, #0x92
	lsls r2, r2, #4
	adds r2, r2, r7
	mov r8, r2
	ldr r0, _081EB238 @ =0x085AE4B0
	mov sb, r0
	adds r5, r7, #0
	adds r5, #0x62
	adds r4, r7, #0
	adds r4, #0x20
_081EB224:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081EB23C
	movs r0, #1
	b _081EB23E
	.align 2, 0
_081EB238: .4byte 0x085AE4B0
_081EB23C:
	movs r0, #0
_081EB23E:
	cmp r0, #0
	beq _081EB252
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, sb
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_081EB252:
	adds r5, #0x48
	adds r4, #0x48
	adds r6, #1
	cmp r6, #0x1f
	ble _081EB224
_081EB25C:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
