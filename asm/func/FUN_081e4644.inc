	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	mov sb, r0
	mov r8, r1
	adds r5, r2, #0
	adds r6, r3, #0
	ldr r7, [sp, #0x1c]
	movs r4, #0
	cmp r4, r6
	bge _081E4680
_081E465C:
	mov r0, r8
	adds r2, r0, r4
	ldr r0, [sp, #0x20]
	mov r1, sb
	bl FUN_081e45e4
	adds r2, r4, #1
	cmp r5, #0
	ble _081E467A
	adds r1, r5, #0
_081E4670:
	strh r7, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bne _081E4670
_081E467A:
	adds r4, r2, #0
	cmp r4, r6
	blt _081E465C
_081E4680:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
