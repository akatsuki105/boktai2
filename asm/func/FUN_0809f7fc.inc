	push {lr}
	adds r3, r0, #0
	ldr r0, _0809F830 @ =0x030046A0
	ldr r0, [r0]
	ldr r1, _0809F834 @ =0x00000942
	adds r0, r0, r1
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp r0, #0
	ble _0809F82C
	adds r0, r3, #0
	adds r0, #0xec
	ldrh r1, [r0]
	adds r1, #1
	strh r1, [r0]
	lsls r1, r1, #0x10
	ldr r0, _0809F838 @ =0x012B0000
	cmp r1, r0
	ble _0809F82C
	ldr r2, _0809F83C @ =FUN_0809f890
	adds r0, r3, #0
	movs r1, #0
	bl Entity1DBEElem_SetState
_0809F82C:
	pop {r0}
	bx r0
	.align 2, 0
_0809F830: .4byte 0x030046A0
_0809F834: .4byte 0x00000942
_0809F838: .4byte 0x012B0000
_0809F83C: .4byte FUN_0809f890
