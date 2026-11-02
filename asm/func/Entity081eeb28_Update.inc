	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	adds r7, r0, #0
	adds r1, r7, #0
	adds r1, #0x1c
	movs r2, #0x97
	lsls r2, r2, #2
	adds r0, r7, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _081EEAA8
	movs r6, #0
	movs r0, #0x97
	lsls r0, r0, #2
	adds r0, r0, r7
	mov r8, r0
	ldr r2, _081EEA84 @ =0x085AE4E0
	mov sb, r2
	adds r5, r7, #0
	adds r5, #0x46
	adds r4, r1, #0
_081EEA72:
	movs r1, #1
	lsls r1, r6
	mov r2, r8
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081EEA88
	movs r0, #1
	b _081EEA8A
	.align 2, 0
_081EEA84: .4byte 0x085AE4E0
_081EEA88:
	movs r0, #0
_081EEA8A:
	cmp r0, #0
	beq _081EEA9E
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, sb
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_081EEA9E:
	adds r5, #0x30
	adds r4, #0x30
	adds r6, #1
	cmp r6, #0xb
	ble _081EEA72
_081EEAA8:
	movs r0, #0
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
