	push {r4, lr}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r4, [r0]
	movs r0, #0x78
	bl VM_SeekToKeyword
	adds r2, r0, #0
	cmp r2, #0
	beq _081001BC
	bl VM_GetPC
	cmp r0, #0
	beq _0810018A
	bl Script_GetValue
	adds r1, r0, #0
	b _0810018C
_0810018A:
	movs r1, #0
_0810018C:
	movs r2, #0xcb
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r1, [r0]
	bl VM_GetPC
	cmp r0, #0
	beq _081001A4
	bl Script_GetValue
	adds r2, r0, #0
	b _081001A6
_081001A4:
	movs r2, #0
_081001A6:
	ldr r1, _081001B4 @ =0x0000065A
	adds r0, r4, r1
	movs r1, #0
	strb r2, [r0]
	ldr r2, _081001B8 @ =0x0000065B
	b _081001CE
	.align 2, 0
_081001B4: .4byte 0x0000065A
_081001B8: .4byte 0x0000065B
_081001BC:
	movs r1, #0xcb
	lsls r1, r1, #3
	adds r0, r4, r1
	movs r1, #0
	strh r2, [r0]
	ldr r2, _081001D8 @ =0x0000065A
	adds r0, r4, r2
	strb r1, [r0]
	adds r2, #1
_081001CE:
	adds r0, r4, r2
	strb r1, [r0]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081001D8: .4byte 0x0000065A
