	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r1, #0x86
	lsls r1, r1, #2
	adds r0, r6, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EA08A
	movs r5, #0
	movs r0, #0x86
	lsls r0, r0, #2
	adds r7, r6, r0
	movs r1, #0x87
	lsls r1, r1, #2
	adds r4, r6, r1
	ldr r0, _081EA068 @ =0x085AE45C
	mov r8, r0
_081EA056:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081EA06C
	movs r0, #1
	b _081EA06E
	.align 2, 0
_081EA068: .4byte 0x085AE45C
_081EA06C:
	movs r0, #0
_081EA06E:
	cmp r0, #0
	beq _081EA082
	ldrb r0, [r4, #0xa]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_081EA082:
	adds r4, #0xc
	adds r5, #1
	cmp r5, #7
	ble _081EA056
_081EA08A:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
