	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r0, #0
	ldr r1, _0809CABC @ =0x000009FE
	adds r0, r5, r1
	movs r4, #0
	strb r4, [r0]
	ldr r0, _0809CAC0 @ =0x0000C091
	ldr r1, _0809CAC4 @ =0x0000A413
	bl GetFile
	str r0, [r5, #0x18]
	ldr r0, _0809CAC8 @ =0x000092B3
	ldr r1, _0809CACC @ =0x0000EFDA
	bl GetFile
	movs r2, #0xda
	lsls r2, r2, #1
	adds r0, r0, r2
	str r0, [r5, #0x30]
	ldr r1, [r5, #0x18]
	str r0, [sp]
	adds r0, r5, #0
	movs r2, #0
	movs r3, #0
	bl FUN_0808a3c4
	ldr r6, _0809CAD0 @ =0x00000A2A
	adds r0, r5, r6
	strb r4, [r0]
	ldr r7, _0809CAD4 @ =0x0000CB05
	mov r8, r7
	ldr r1, _0809CAD8 @ =0x00005D04
	mov r0, r8
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809CAB0
	adds r0, r5, #0
	adds r0, #0xa0
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r6, r7}
	stm r2!, {r4, r6, r7}
	ldm r1!, {r4, r6, r7}
	stm r2!, {r4, r6, r7}
	ldm r1!, {r4, r6}
	stm r2!, {r4, r6}
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0809CADC @ =0x0000B343
	mov r0, r8
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809CAB0
	adds r0, r5, #0
	adds r0, #0x60
	adds r1, r3, #0
	ldm r1!, {r2, r4, r7}
	stm r0!, {r2, r4, r7}
	ldm r1!, {r2, r6, r7}
	stm r0!, {r2, r6, r7}
	ldm r1!, {r4, r6}
	stm r0!, {r4, r6}
	adds r0, r5, #0
	adds r0, #0x60
	adds r1, r3, #0
	bl OpenMainSpriteFile
	adds r0, r5, #0
	bl FUN_0808cf64
	adds r0, r5, #0
	bl FUN_0808d01c
	adds r0, r5, #0
	bl FUN_0809c960
_0809CAB0:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809CABC: .4byte 0x000009FE
_0809CAC0: .4byte 0x0000C091
_0809CAC4: .4byte 0x0000A413
_0809CAC8: .4byte 0x000092B3
_0809CACC: .4byte 0x0000EFDA
_0809CAD0: .4byte 0x00000A2A
_0809CAD4: .4byte 0x0000CB05
_0809CAD8: .4byte 0x00005D04
_0809CADC: .4byte 0x0000B343
