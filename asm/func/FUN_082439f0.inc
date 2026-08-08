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
	bne _08243A18
	adds r0, r6, #0
	bl FUN_08243648
	cmp r6, r0
	bne _08243A18
	ldr r0, _08243A20 @ =0x00001FF8
	cmp r6, r0
	ble _08243A24
_08243A18:
	movs r0, #1
	rsbs r0, r0, #0
	b _08243A4C
	.align 2, 0
_08243A20: .4byte 0x00001FF8
_08243A24:
	bl FUN_08243660
	movs r4, #1
	rsbs r4, r4, #0
	movs r5, #0
	b _08243A32
_08243A30:
	adds r5, #1
_08243A32:
	cmp r5, #7
	bgt _08243A46
	mov r0, r8
	adds r1, r7, #0
	adds r2, r6, #0
	bl FUN_08243828
	adds r4, r0, #0
	cmp r4, #0
	blt _08243A30
_08243A46:
	bl FUN_082436dc
	adds r0, r4, #0
_08243A4C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
