	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r6, r0, #0
	adds r4, r1, #0
	adds r5, r2, #0
	adds r7, r3, #0
	ldr r0, _08247460 @ =0x030026B0
	ldr r0, [r0]
	mov sl, r0
	cmp r0, #0
	bne _08247464
	movs r0, #0
	movs r1, #0
	bl SSE_Create
	mov sl, r0
	cmp r0, #0
	bne _08247464
	movs r0, #1
	rsbs r0, r0, #0
	b _082474EC
	.align 2, 0
_08247460: .4byte 0x030026B0
_08247464:
	movs r0, #0
	strb r0, [r6]
	str r4, [r6, #8]
	strb r0, [r6, #2]
	strb r0, [r6, #3]
	strb r5, [r6, #1]
	strb r7, [r6, #4]
	ldr r0, [sp, #0x24]
	strb r0, [r6, #5]
	movs r0, #0x96
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r0, _082474FC @ =FUN_0824666c
	str r0, [r1]
	movs r7, #0
	movs r1, #0x44
	adds r1, r1, r6
	mov r8, r1
	adds r5, r6, #0
	adds r5, #0x1c
	adds r4, r6, #0
	adds r4, #0xc
	movs r0, #3
	mov sb, r0
_08247494:
	strb r7, [r4]
	strh r7, [r4, #2]
	strh r7, [r4, #8]
	strh r7, [r4, #0xa]
	strh r7, [r4, #0xc]
	ldr r1, _08247500 @ =0x030026B0
	ldr r0, [r1]
	ldr r1, [r0, #0x18]
	adds r0, r5, #0
	movs r2, #0x11
	bl FUN_0822d9f0
	adds r0, r5, #0
	movs r1, #8
	rsbs r1, r1, #0
	adds r2, r1, #0
	bl FUN_0822dad4
	movs r0, #2
	strb r0, [r4, #0x1f]
	ldr r1, _08247500 @ =0x030026B0
	ldr r0, [r1]
	ldr r1, [r0, #0x1c]
	str r7, [sp]
	mov r0, r8
	movs r2, #0
	movs r3, #0
	bl FUN_08236fac
	movs r0, #0x48
	add r8, r0
	adds r5, #0x48
	adds r4, #0x48
	movs r1, #1
	rsbs r1, r1, #0
	add sb, r1
	mov r0, sb
	cmp r0, #0
	bge _08247494
	mov r0, sl
	adds r1, r6, #0
	bl FUN_08246670
	movs r0, #0
_082474EC:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_082474FC: .4byte FUN_0824666c
_08247500: .4byte 0x030026B0
