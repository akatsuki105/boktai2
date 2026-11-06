	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x3c
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _081F8980
	movs r7, #0
	ldr r0, _081F8958 @ =0x085AE5C0
	mov r8, r0
	movs r0, #0xad
	lsls r0, r0, #1
	adds r6, r4, r0
	adds r5, r1, #0
_081F8948:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F895C
	movs r0, #1
	b _081F895E
	.align 2, 0
_081F8958: .4byte 0x085AE5C0
_081F895C:
	movs r0, #0
_081F895E:
	cmp r0, #0
	beq _081F8972
	ldrb r0, [r6]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
_081F8972:
	movs r0, #0x92
	lsls r0, r0, #1
	adds r6, r6, r0
	adds r5, r5, r0
	adds r7, #1
	cmp r7, #7
	ble _081F8948
_081F8980:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
