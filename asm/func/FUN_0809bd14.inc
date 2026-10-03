	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	ldr r5, _0809BEB0 @ =0x0000CB05
	ldr r1, _0809BEB4 @ =0x0000B343
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0809BD2A
	b _0809BEA8
_0809BD2A:
	adds r1, r4, #0
	adds r1, #0x60
	ldm r0!, {r2, r6, r7}
	stm r1!, {r2, r6, r7}
	ldm r0!, {r2, r6, r7}
	stm r1!, {r2, r6, r7}
	ldm r0!, {r2, r6}
	stm r1!, {r2, r6}
	adds r0, r4, #0
	adds r0, #0x60
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0809BEB8 @ =0x00005D04
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0809BD54
	b _0809BEA8
_0809BD54:
	movs r7, #0xa0
	adds r7, r7, r4
	mov ip, r7
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6}
	stm r2!, {r0, r6}
	mov r0, ip
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0809BEBC @ =0x00000312
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	bne _0809BD82
	b _0809BEA8
_0809BD82:
	adds r1, r4, #0
	adds r1, #0x80
	ldm r0!, {r2, r6, r7}
	stm r1!, {r2, r6, r7}
	ldm r0!, {r2, r6, r7}
	stm r1!, {r2, r6, r7}
	ldm r0!, {r2, r7}
	stm r1!, {r2, r7}
	adds r0, r4, #0
	adds r0, #0x80
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0809BEC0 @ =0x000092F0
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r6, #0xc0
	adds r6, r6, r4
	mov ip, r6
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r7}
	stm r2!, {r0, r7}
	mov r0, ip
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0809BEC4 @ =0x0000DE23
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r1, #0x80
	lsls r1, r1, #1
	adds r1, r1, r4
	mov ip, r1
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r6, r7}
	stm r2!, {r6, r7}
	mov r0, ip
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0809BEC8 @ =0x0000DFDE
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r0, #0x90
	lsls r0, r0, #1
	adds r0, r0, r4
	mov ip, r0
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r6, r7}
	stm r2!, {r6, r7}
	mov r0, ip
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0809BECC @ =0x0000E2DE
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r0, #0xa0
	lsls r0, r0, #1
	adds r0, r0, r4
	mov ip, r0
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r6, r7}
	stm r2!, {r6, r7}
	mov r0, ip
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0809BED0 @ =0x0000D27A
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r0, #0xe0
	adds r0, r0, r4
	mov ip, r0
	mov r2, ip
	adds r1, r3, #0
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r0, r6, r7}
	stm r2!, {r0, r6, r7}
	ldm r1!, {r6, r7}
	stm r2!, {r6, r7}
	mov r0, ip
	adds r1, r3, #0
	bl OpenMainSpriteFile
	ldr r1, _0809BED4 @ =0x0000DCC1
	adds r0, r5, #0
	bl GetFile
	adds r3, r0, #0
	cmp r3, #0
	beq _0809BEA8
	movs r1, #0xb0
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r2, r0, #0
	adds r1, r3, #0
	ldm r1!, {r4, r5, r6}
	stm r2!, {r4, r5, r6}
	ldm r1!, {r4, r5, r7}
	stm r2!, {r4, r5, r7}
	ldm r1!, {r6, r7}
	stm r2!, {r6, r7}
	adds r1, r3, #0
	bl OpenMainSpriteFile
_0809BEA8:
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0809BEB0: .4byte 0x0000CB05
_0809BEB4: .4byte 0x0000B343
_0809BEB8: .4byte 0x00005D04
_0809BEBC: .4byte 0x00000312
_0809BEC0: .4byte 0x000092F0
_0809BEC4: .4byte 0x0000DE23
_0809BEC8: .4byte 0x0000DFDE
_0809BECC: .4byte 0x0000E2DE
_0809BED0: .4byte 0x0000D27A
_0809BED4: .4byte 0x0000DCC1
