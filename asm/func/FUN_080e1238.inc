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
	bge _080E1274
_080E1250:
	mov r0, r8
	adds r2, r0, r4
	ldr r0, [sp, #0x20]
	mov r1, sb
	bl FUN_080e1218
	adds r2, r4, #1
	cmp r5, #0
	ble _080E126E
	adds r1, r5, #0
_080E1264:
	strh r7, [r0]
	adds r0, #2
	subs r1, #1
	cmp r1, #0
	bne _080E1264
_080E126E:
	adds r4, r2, #0
	cmp r4, r6
	blt _080E1250
_080E1274:
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
