	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x1c
	ldr r1, _081D162C @ =0x0000097C
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081D165A
	movs r4, #0
	ldr r0, _081D162C @ =0x0000097C
	adds r6, r5, r0
	ldr r1, _081D1630 @ =0x085AE0B8
	mov r8, r1
_081D161C:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081D1634
	movs r0, #1
	b _081D1636
	.align 2, 0
_081D162C: .4byte 0x0000097C
_081D1630: .4byte 0x085AE0B8
_081D1634:
	movs r0, #0
_081D1636:
	cmp r0, #0
	beq _081D1654
	movs r0, #0xc8
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	adds r0, r1, #0
	adds r0, #0xb0
	ldrh r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081D1654:
	adds r4, #1
	cmp r4, #0xb
	ble _081D161C
_081D165A:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
