	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r1, #0
	adds r6, r2, #0
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	mov r8, r0
	movs r0, #1
	ands r0, r7
	cmp r0, #0
	bne _082439B0
	adds r0, r6, #0
	bl FUN_08243648
	cmp r6, r0
	bne _082439B0
	ldr r0, _082439B8 @ =0x00001FF8
	cmp r6, r0
	ble _082439BC
_082439B0:
	movs r0, #1
	rsbs r0, r0, #0
	b _082439E4
	.align 2, 0
_082439B8: .4byte 0x00001FF8
_082439BC:
	bl FUN_08243660
	movs r4, #1
	rsbs r4, r4, #0
	movs r5, #0
	b _082439CA
_082439C8:
	adds r5, #1
_082439CA:
	cmp r5, #7
	bgt _082439DE
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_0824374c
	adds r4, r0, #0
	cmp r4, #0
	blt _082439C8
_082439DE:
	bl FUN_082436dc
	adds r0, r4, #0
_082439E4:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
